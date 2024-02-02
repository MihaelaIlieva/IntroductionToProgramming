/**
*
* Solution to homework assignment 1
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

#include <iostream>;
using namespace std;

int main() {
	// number is the number given by the user, the name N was given in the requirements for it
	int number = 0;
	// counter counts the number of N's dividers
	int counter = 0;
	// firstDivider, secondDivider and thirdDivider are the three dividers of N that should make the min sum, the names m,p and q were given in the requirements for them
	int firstDivider = 0;
	int secondDivider = 0;
	int thirdDivider = 0;
	// sum keeps the current min sum
	int sum = INT_MAX;

	// waiting for the user to insert a valid number
	while (number<1 || number>pow(10, 9)) {
		cin >> number;
	}
	// checking if the number is prime
	for (int i = 1; i <= number; i++) {
		if (number % i == 0) { counter++; }
	}
	if (counter <= 2) { firstDivider = 1; secondDivider = 1; thirdDivider = number; sum = firstDivider+secondDivider+thirdDivider; }
	else {
		for (int i = 1; i <= number; i++) {
			for (int j = 1; j <= number; j++) {
				for (int k = 1; k <= number; k++) {
					if (i * j * k == number && i + j + k < sum) {
						sum = i + j + k;
						firstDivider = i;
						secondDivider = j;
						thirdDivider = k;
					}
				}
			}
		}
	}
	cout << firstDivider << " " << secondDivider << " " << thirdDivider;
}