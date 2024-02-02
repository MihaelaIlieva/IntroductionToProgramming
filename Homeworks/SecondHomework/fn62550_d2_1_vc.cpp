/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Mihaela Ilieva
* @idnumber 62550
* @task 1
* @compiler VC
*
*/

#include <iostream>
#include <vector>
using namespace std;

// AbsoluteValue(int number) is a function for getting the absolute value of a number
int AbsoluteValue(int number){
	return (number >= 0) ? number : -number;
}

int main() {

	// checking if the size given by the user is valid
	int vectorSize=0;
	while (vectorSize < 3 || vectorSize>100) {
		cin >> vectorSize;
	}
	
	// the vector numbers will keep the numbers given by the user
	vector<int>numbers;

	// inserting the numbers in the vector
	for (size_t i = 0; i < vectorSize; i++)
	{
		//currentNumber is for checking if the current number is valid
		int currentNumber = 0;
		while (currentNumber<=0)
		{
			cin >> currentNumber;
		}
		numbers.push_back(currentNumber);
	}
	// upperChecker is where the cheching begins to repeat
	int upperChecker = 0;

	//if the numbers' count is even vectorSize/2-1 is where the values on both sides are equivalent
	//for example if vectorSize is 6 then vectorSize/2-1=2 and we will compare |numbers[2]-numbers[3]| and |numbers[3]-numbers[2]|
	//after that the previous checks begin to repeat themselves
	if (vectorSize % 2 == 0) {
		upperChecker = vectorSize / 2 - 1;
	}
	else {
		upperChecker = vectorSize / 2;
	}
	
	// checking if the given numbers cover the requirements
	for (size_t i = 0; i < upperChecker; i++)
		{
			if (AbsoluteValue(numbers[i] - numbers[i + 1]) != AbsoluteValue(numbers[vectorSize - (i+ 1)] - numbers[vectorSize - (i + 2)])) {
				cout << 0;
				return 0;
			}
		}
	cout << 1;
	return 0;
}