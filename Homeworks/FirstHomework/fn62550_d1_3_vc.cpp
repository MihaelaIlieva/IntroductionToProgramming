/**
*
* Solution to homework assignment 1
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

#include <iostream>;
using namespace std;

int main() {
	// the three numbers that will be given
	int firstNumber = -1;
	int secondNumber = -1;
	int thirdNumber = -1;

	int palindrom=0;

	// checking if the given numbers are digits and waiting untill they are
	while (firstNumber < 0 || firstNumber>9) {
		cin >> firstNumber;
	}
	while (secondNumber < 0 || secondNumber>9) {
		cin >> secondNumber;
	}
	while (thirdNumber < 0 || thirdNumber>9) {
		cin >> thirdNumber;
	}
	// 1 1 1 111
	// 0 0 0 0
	if (firstNumber == secondNumber && firstNumber == thirdNumber) {
		if (firstNumber == 0) { palindrom = 0; }
		else {
			palindrom = 100 * firstNumber + 10 * secondNumber + thirdNumber;
		}
	} // 1 1 2 121
	  // 0 0 1 1001
	else if (firstNumber == secondNumber && firstNumber != thirdNumber) { 
		if (firstNumber != 0) {
		palindrom = 100 * firstNumber + 10 * thirdNumber + secondNumber; }
		else {
			palindrom = 1000 * thirdNumber + thirdNumber;
		}
	} // 2 1 2 212
	  // 0 1 0 1001
	else if (firstNumber == thirdNumber && firstNumber != secondNumber) {
		if (firstNumber != 0) {
			palindrom = 100 * firstNumber + 10 * secondNumber + thirdNumber;
		}
		else {
			palindrom = 1000 * secondNumber + secondNumber;
		}
	} // 1 2 2 212
	  // 1 0 0 1001
	else if (secondNumber == thirdNumber && secondNumber != firstNumber) {
		if (secondNumber != 0) {
			palindrom = 100 * secondNumber + 10 * firstNumber + thirdNumber;
		}
		else {
			palindrom = 1000 * firstNumber + firstNumber;
		}
	} // 1 2 3 12321
	else { 
		if (firstNumber > secondNumber && firstNumber > thirdNumber) {
			if ((secondNumber > thirdNumber&&thirdNumber!=0)||(secondNumber<thirdNumber&&secondNumber==0)) {				
					palindrom = 10000 * thirdNumber + 1000 * secondNumber + 100 * firstNumber + 10 * secondNumber + thirdNumber;
			}			
			else {				
					palindrom = 10000 * secondNumber + 1000 * thirdNumber + 100 * firstNumber + 10 * thirdNumber + secondNumber;
			}
		}
		if (secondNumber > firstNumber && secondNumber > thirdNumber) {
			if ((firstNumber > thirdNumber && thirdNumber != 0) || (firstNumber < thirdNumber && firstNumber == 0)) {
				palindrom = 10000 * thirdNumber + 1000 * firstNumber + 100 * secondNumber + 10 * firstNumber + thirdNumber;
			}
			else {				
					palindrom = 10000 * firstNumber + 1000 * thirdNumber + 100 * secondNumber + 10 * thirdNumber + firstNumber;
			}
		}
		if (thirdNumber > firstNumber && thirdNumber > secondNumber) {
			if ((firstNumber > secondNumber&&secondNumber!=0)||(firstNumber<secondNumber&&firstNumber==0)) {				
					palindrom = 10000 * secondNumber + 1000 * firstNumber + 100 * thirdNumber + 10 * firstNumber + secondNumber;
			}
			else {				
					palindrom = 10000 * firstNumber + 1000 * secondNumber + 100 * thirdNumber + 10 * secondNumber + firstNumber;
			}
		}
	}
	cout << palindrom;
}