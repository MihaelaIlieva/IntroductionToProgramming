/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Mihaela Ilieva
* @idnumber 62550
* @task 4
* @compiler VC
*
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {

	// checking if the size given by the user is valid
	int vectorSize = 0;
	while (vectorSize < 3 || vectorSize>100) {
		cin >> vectorSize;
	}

	// the vector numbers will keep the unique numbers given by the user
	vector<int> numbers;

	//currentNumber will hold the current number that is inserted
	int currentNumber = 0;

	// checking if the currentNumber is unique for the vector numbers and inserting it in the vector only if it is not already there
	while(numbers.size()!=vectorSize){
		cin >> currentNumber;
		// checker shows how many times the currentNumber is seen in the vector numbers : 0 if it's not there and 1 if it already is there
		int checker = 0;
		for (size_t i = 0; i < numbers.size(); i++)
		{
			if (currentNumber == numbers[i]) {
				checker++;
			}
		}
		if (checker == 0) {
			numbers.push_back(currentNumber);
		}
	}

	// countOfNullSums counts how many sums of three different numbers are equal to zero
	int countOfNullSums = 0;

	// finding the sums that are equal to zero and counting them
	for (size_t i = 0; i < vectorSize; i++)
	{
		for (size_t j = i+1; j < vectorSize; j++)
		{
			for (size_t k = j+1; k < vectorSize; k++)
			{
				if (numbers[i] + numbers[j] + numbers[k] == 0) {
					countOfNullSums++;
				}
			}
		}
	}

	cout << countOfNullSums;

	return 0;
}