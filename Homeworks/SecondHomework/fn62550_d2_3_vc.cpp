/**
*
* Solution to homework assignment 2
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

//palindromesCount keeps how many palindromes we have counted
int palindromesCount = 0;

//the function SearchForLongerPalindromes finds longer palindroms that have shorter ones in them, for example 50605 when we find 060 we search for 50605
void SearchForLongerPalindromes(vector<int> numbers, int firstNumberIndex, int lastNumberIndex) {
	while (firstNumberIndex >= 0 && lastNumberIndex <= numbers.size() - 1) {
		if (numbers[firstNumberIndex] == numbers[lastNumberIndex]) {
			palindromesCount++;
			firstNumberIndex--;
			lastNumberIndex++;
		}
		else {
			break;
		}
	}
}

int main() {

	//checking if the size given by the user is valid
	int vectorSize = 0;
	while (vectorSize < 3 || vectorSize>1000) {
		cin >> vectorSize;
	}

	//the vector numbers keeps the numbers given by the user
	vector<int> numbers;

	//inserting the numbers that are valid in the vector
	for (size_t i = 0; i < vectorSize; i++)
	{
		//currentNumber is for checking if the current number is valid
		int currentNumber = -1;
		while (currentNumber < 0 || currentNumber>9) {
			cin >> currentNumber;
		}
		numbers.push_back(currentNumber);
	}
	// searching for palindromes in the vector
	for (size_t i = 0; i <= vectorSize-3; i++)
	{
		int firstNumberIndex = i;
		int middleNumberIndex = i + 1;
		int lastNumberIndex = i + 2;

		// gets the odd-digited palindromes
		if (numbers[firstNumberIndex] == numbers[lastNumberIndex]) {
			palindromesCount++;
			SearchForLongerPalindromes(numbers, firstNumberIndex - 1, lastNumberIndex + 1);
		}
		// gets the even-digited palindromes
		if (numbers[middleNumberIndex] == numbers[lastNumberIndex]) {
			SearchForLongerPalindromes(numbers, firstNumberIndex, lastNumberIndex + 1);
		}
	}
	if (palindromesCount == 0) {
		cout << -1;
	}
	else {
		cout << palindromesCount;
	}
	
	return 0;
}