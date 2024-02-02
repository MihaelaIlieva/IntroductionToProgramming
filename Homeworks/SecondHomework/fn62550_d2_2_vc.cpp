/**
*
* Solution to homework assignment 2
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

#include <iostream>
#include <vector>
using namespace std;

int main() {

	//checking if the size(days) given by the user is valid
	int daysGiven = 0;
	while (daysGiven < 3 || daysGiven>365) {
		cin >> daysGiven;
	}

	//the vector companyShares will keep the shares for each of the given days
	vector<double>companyShares;

	//inserting the shares in the vector that are valid
	for (size_t i = 0; i < daysGiven; i++)
	{
		double currentShare = 0.0;
		while (currentShare < 0.1 || currentShare>100) {
			cin >> currentShare;
		}
		companyShares.push_back(currentShare);
	}

	//haveBought shows if we have already bought a share, if we have, we should sell it before buying another one
	bool haveBought = false;

	//profit keeps the amount of money we have made
	double profit = 0;


	//we should buy if the next day the share is more expensive
	// we should sell if the next day the share is cheaper or its the last day
	for (size_t i = 0; i < daysGiven; i++)
	{
		if (i >= 0 && i < daysGiven - 1) {


			if (haveBought == false && companyShares[i] < companyShares[i + 1] ) {
				profit -= companyShares[i];
				haveBought = true;
			}
			else if (haveBought == true && companyShares[i] > companyShares[i + 1]) {
				profit += companyShares[i];
				haveBought = false;
			}
		}
		// if we have bought a share and haven't sold it untill the last day, we should sell it then
		else {
			if (haveBought == true) {
				profit += companyShares[i];
			}
		}
	}

	cout << profit;

	return 0;
}