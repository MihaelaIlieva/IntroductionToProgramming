/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Mihaela Ilieva
* @idnumber 62550
* @task 5
* @compiler VC
*
*/
#include <iostream>;
using namespace std;
int main() {
	// divider is the divider that will be checked, the name N was given in the requirements for it
	int divider = 0;
	// divider will be changed in the proccess so startValueOfDivider will hold the start value of it
	int startValueOfDivider = 0;
	// result holds the value of 1/divider
	double result = 0;
	// intResult is to check if all the digits after the dot are counted
	int intResult = 0;
	// counter counts the digits after the dot
	int counter = 0;

	// waiting for the user to insert a proper divider
	while (divider<2 || divider>pow(10, 9)) {
		cin >> divider;
		startValueOfDivider = divider;
	}	
	// 1/divider is not infinite if divider's dividers are only 2's and/or 5's
	while (divider != 1) {
		if (divider % 2 == 0) { divider /= 2; }
		else if (divider % 5 == 0) { divider /= 5; }
		else { break;}
	}
	// 1/divider is not infinite
	if (divider == 1) {
		result = 1.0 / startValueOfDivider;
		while (true) {
			result = result * 10;
			intResult = result;
			if (intResult % 10 != 0||(intResult%10==0&&result-intResult!=0)) { counter++; }
			else { break; }
		}
		cout << counter;
	}
	// 1/divider is infinite
	else {
		cout << "NO";
	}
}
