/**
*
* Solution to homework assignment 1
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

#include<iostream>
using namespace std;
int main() {
	/*	 numberOfBirthdays is the number of birthdays, the name n was given in the reqirements for it
		 moneyNeeded is the amount of money needed for the laptop, the name x was given in the requirements for it / since it's about money I made it double because the requirements weren't clear about its type
		  toyPrice is how much is one toy worth, the name m was given in the reqierements for it / since it's about money I made it double because the requirements weren't clear about its type
	*/
	int numberOfBirthdays = -1;
	double moneyNeeded = -1, toyPrice = -1;
	// moneyEarned is to keep track of how much money he has
	double moneyEarned = 0;
	// sumToBeAdded is how much money he will receive on his even birthdays, it starts from 30 for his second birthday
	int sumToBeAdded = 30;
	//FRIENDS_TREAT is how much money he has to spend on even birthdays for his friends
	const int FRIENDS_TREAT = 5;
	// checking if the given numbers are valid
	while (numberOfBirthdays <= 0) {
		cin >> numberOfBirthdays;
	}
	while (moneyNeeded <= 0) {
		cin >> moneyNeeded;
	}
	while (toyPrice <= 0) {
		cin >> toyPrice;
	}

	

	for (int i = 1; i <= numberOfBirthdays; i++)
	{
		if (i % 2 != 0) {
			moneyEarned += toyPrice;
		}
		else {
			if (i != 2) { sumToBeAdded += 30; }
			moneyEarned += sumToBeAdded;
			moneyEarned -= FRIENDS_TREAT;
		}
	}
	if (moneyEarned >= moneyNeeded) {
		cout << "yes" << endl;
		cout << moneyEarned - moneyNeeded << endl;
	}
	else {
		cout << "no" << endl;
		cout << moneyNeeded - moneyEarned << endl;
	}
	return 0;
}