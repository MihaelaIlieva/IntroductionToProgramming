/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Mihaela Ilieva
* @idnumber 62550
* @task 2
* @compiler VC
*
*/

#include<iostream>
using namespace std;
int main() {
	// number is the current number that the user inserts
	int number=0;
	//maxNumber is for comparison in order to get the second max number
	int maxNumber=0;
	// secondMaxNumber is to keep the current second max number
	int secondMaxNumber=0;
	// to check if there are at least two different numbers
	int differentNumber1 =0;
	// count counts how many numbers are different
	// when changing the value of differentNumber1 -> count++
	int count = 0;
	
	// inserting numbers until a number<=0 is inserted
	while (true) {
		cin >> number;
		
		if (number <= 0) {break; }
		else {
			if (number > maxNumber) {
				secondMaxNumber = maxNumber;
				maxNumber = number;
				if (number != differentNumber1) {
					differentNumber1 = number;
					count++;
				}
			}
			
		}
	}
	// count=0 shows that a number<=0 was inserted directly
	// count=1 shows that differentNumber1 was changed only once for the first number
	// count=2 shows that there are now two diffent numbers
	if (count <= 1) { cout << -1; }
	else {
		cout << secondMaxNumber << endl;
		
	}
	return 0;	
}