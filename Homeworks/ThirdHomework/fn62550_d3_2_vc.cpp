/**
*
* Solution to homework assignment 3
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

using namespace std;

// gets the number of symbols in the array
int getArrayNumberOfSymbols(char arrayOfSymbols[]) {
		int i = 0;
		while (arrayOfSymbols[i] != '\0') {
			i++;
		}
		return i;
	}

//checking if the symbols we want to remove are in the concatenation -> if we have a chance for  having correctly concatenated char arrays
bool RemoveMatchingSymbols(char symbolToRemove[], int symbolsToRemoveSize, char probableConcatenation[], int probableConcatenationSize)
{
	int matchesFound = 0;
	int foundAtFront = 0;
	int foundAtBack = 0;

	// checking if there is a match  at front
	for (size_t i = 0; i < symbolsToRemoveSize; i++)
	{
		for (size_t j = 0; j < symbolsToRemoveSize; j++)
		{
			if (symbolToRemove[i] == probableConcatenation[j])
			{
				foundAtFront++;
				continue;
			}
		}
	}

	// checking if there is a match at back
	for (size_t i = 0; i < symbolsToRemoveSize; i++)
	{
		for (size_t j = probableConcatenationSize - symbolsToRemoveSize - 1; j < probableConcatenationSize; j++)
		{
			if (symbolToRemove[i] == probableConcatenation[j])
			{
				foundAtBack++;
				continue;
			}
		}
	}

	if (foundAtFront > foundAtBack && foundAtFront == symbolsToRemoveSize)
	{
		for (size_t i = 0; i < symbolsToRemoveSize; i++)
		{
			for (size_t j = 0; j < symbolsToRemoveSize; j++)
			{
				if (symbolToRemove[i] == probableConcatenation[j])
				{
					matchesFound++;
					for (int z = j; z < probableConcatenationSize; ++z)
					{
						probableConcatenation[z] = probableConcatenation[z + 1]; 
					}
					break;
				}
			}
		}

	}
	else if (foundAtBack > foundAtFront && foundAtBack == symbolsToRemoveSize)
	{
		for (size_t i = 0; i < symbolsToRemoveSize; i++)
		{
			for (size_t j = probableConcatenationSize - symbolsToRemoveSize - 1; j < probableConcatenationSize; j++)
			{
				if (symbolToRemove[i] == probableConcatenation[j])
				{
					matchesFound++;
					continue;
				}
			}
		}
	}
	return symbolsToRemoveSize == matchesFound;

}

// checking if  the conatenation is possible and if so then checking if it is correct
bool IsConcatenationCorrect(char firstSymbols[], char secondSymbols[], char probableConcatenation[]) {
			
	int numberOfFirstSymbols = getArrayNumberOfSymbols(firstSymbols);
	int numberOfSecondSymbols = getArrayNumberOfSymbols(secondSymbols);	
	int numberOfProbableConcatenationSymbols = getArrayNumberOfSymbols(probableConcatenation);

	// checking if the concatenation is possible, you cannot get 9 symbols in a char by combining one of 3 symbols and one of 5 symbols
	if (numberOfFirstSymbols + numberOfSecondSymbols != numberOfProbableConcatenationSymbols) { return false; }
	else {
		// if both ends of the possible concatenation match the  either the first or second symbols then the concatenation is correct
		if (RemoveMatchingSymbols(firstSymbols, numberOfFirstSymbols, probableConcatenation, numberOfProbableConcatenationSymbols)
			&& RemoveMatchingSymbols(secondSymbols, numberOfSecondSymbols, probableConcatenation, numberOfProbableConcatenationSymbols))
		{
			return true;
		}
		return false;
	
	}
}
// checking if an array's symbols are only small letters, if not the given value is invalid
int IsCharArrayValid(char arrayOfSymbols[], int maxSize) {
	for (size_t i = 0; i < maxSize; i++)
	{
		if (arrayOfSymbols[i] == '\0') { break; }
		if (arrayOfSymbols[i] < 'a' || arrayOfSymbols[i]>'z') {
			return -1;
		}
	}
	return 0;
   }

int main() {

	// inserting the symbols in the arrays
	char firstSymbols[151];
	cin.getline(firstSymbols, 151);
	char secondSymbols[151];
	cin.getline(secondSymbols, 151);
	char probableConcatenation[151];
	cin.getline(probableConcatenation, 151);

	// checking if the symbols are all valid
	int validCodeForFirstArray = IsCharArrayValid(firstSymbols, 151);
	int validCodeForSecondArray = IsCharArrayValid(secondSymbols, 151);
	int validCodeForConcatenatedArray = IsCharArrayValid(probableConcatenation, 151);
	// if only one is invalid the program should print -1 and stop
	if (validCodeForFirstArray == -1 || validCodeForSecondArray == -1 || validCodeForConcatenatedArray == -1) {
		cout << -1;
		return 0;
	}
	//if all three arrays are of valid symbols we check for correct concatenation and print the result 0 or 1
	cout << IsConcatenationCorrect(firstSymbols,secondSymbols,probableConcatenation);

	return 0;
}