/**
*
* Solution to homework assignment 3
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Mihaela Ilieva
* @idnumber 62550
* @task 3
* @compiler VC
*
*/

#include <iostream>
#include <vector>

using namespace std;

//getting the sum of particular row
double RowSum(vector<vector<double>> matrix, int row) {
	double sumOfRow = 0;
	for (size_t i = 0; i < matrix[row].size(); i++)
	{
		sumOfRow += matrix[row][i];
	}

	return sumOfRow;
}
//getting the sum of particular column
double ColumnSum(vector<vector<double>> matrix, int col) {
	double sumOfCol = 0;
	for (size_t i = 0; i < matrix.size(); i++)
	{
		sumOfCol += matrix[i][col];
	}

	return sumOfCol;
}
//getting the sum of both diagonals and checking if they are equal to each other and to the sum they should be equal in order for the matrix to be magical
bool DiagonalsSumEquality(vector<vector<double>> matrix, double sumNeededToBeEqual) {

	double sumOfFirstDiagonal = 0;
	for (size_t i = 0; i < matrix.size(); i++)
	{
		sumOfFirstDiagonal += matrix[i][i];
	}

	double sumOfSecondDiagonal = 0;

	for (int i = matrix.size()-1; i >=0 ; i--)
	{
		sumOfSecondDiagonal += matrix[i][i];
	}

	return (sumOfFirstDiagonal == sumOfSecondDiagonal && sumOfFirstDiagonal == sumNeededToBeEqual);
}
// checking if the matrix is a magical square a.k.a checking if the sums of rows,colums and diagonals are equal
bool CheckIfTheMatrixIsMagicalSquare(vector<vector<double>> matrix) {

	//checking if the sum of all rows is the same
	double sumNeededToBeEqual = RowSum(matrix, 0);
	for (size_t i = 1; i < matrix.size(); i++)
	{
		if (sumNeededToBeEqual != RowSum(matrix, i)) { return false; }
	}
	//checking if the sum of all columns is the same
	for (size_t i = 0; i < matrix[0].size(); i++)
	{
		if (sumNeededToBeEqual != ColumnSum(matrix, i)) { return false; }
	}

	// if the sum of all rows is equal to the sum of all columns we check if it equal to the diagonals and if it is then the matrix is a magical square
	return DiagonalsSumEquality(matrix, sumNeededToBeEqual);
}

int main() {

	// inserting the size of the matrix
	int numberOfRowsAndCols = 0;
	while (numberOfRowsAndCols <= 1 || numberOfRowsAndCols >= 1000) {
		cin >> numberOfRowsAndCols;
	}
	// the matrix of double numbers
	vector<vector<double>> matrix(numberOfRowsAndCols,vector<double>(numberOfRowsAndCols,0.0));

	// inserting the numbers into the matrix	
	for (size_t i = 0; i <numberOfRowsAndCols; i++)
	{
		for (size_t j = 0; j < numberOfRowsAndCols; j++)
		{
			cin >> matrix[i][j];
			
		}
	}

	// checking if the values of the numbers are valid
	// if not we print -1 and stop the program
	for (size_t i = 0; i < numberOfRowsAndCols; i++)
	{
		for (size_t j = 0; j < numberOfRowsAndCols; j++)
		{
			if (matrix[i][j] < 0 || matrix[i][j]>100) {
				cout << -1;
				return 0;
			}
		}
	}
	// if the values are valid we check if the matrix is a magical square
	bool isMagicalSquare=CheckIfTheMatrixIsMagicalSquare(matrix);
	if (isMagicalSquare) {
		cout << "true";
	}
	else {
		cout << "false";
	}
	return 0;
}