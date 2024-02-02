//Mihaela Ilieva fn 62550
#include <iostream>
#include <vector>
using namespace std;

int main() {

	//the number given by the user
	int number = 0;
	//working only with positive digits
	while (number <= 0) {
     cin >> number;
	}
	
	//holds the sum of all digits
	int sumOfAllDigits = 0;
	//holds the number's digits
	vector<int>digits;
	
	if (number <= 9) { cout << "false"; }
	else {
		int newNumber = number;

		//getting all the digits and putting them in the vector
		while (newNumber >= 1) {
			sumOfAllDigits += newNumber % 10;
			digits.push_back(newNumber % 10);
			newNumber = newNumber / 10;
		}

		//getting the number by the first two digits
		int firstDigit = digits[digits.size()-1];
		int secondDigit = digits[digits.size()-2];
		int twoDigitNumber = 10 * firstDigit + secondDigit;

		//checking if the condition is true or false
		if (twoDigitNumber == sumOfAllDigits) { cout << "true"; }
		else {
			cout << "false";
		}

	}
	return 0;
}