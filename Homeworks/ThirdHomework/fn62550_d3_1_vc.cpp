/**
*
* Solution to homework assignment 3
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

using namespace std;

// checking if an array contains a particular symbol
bool ContainsInCharArray(char symbols[], int arraySize, char symbol)
{
	for (size_t i = 0; i < arraySize; i++)
	{
		if (symbols[i] == '\0') { break; }
		if (symbols[i] == symbol)
		{
			return true;
		}
	}
	return false;
}

// checking if an array is a correct symbols' combination with maximum of 1 deleted symbol
int CorrectSymbolsCombination(char checkedArray[],int arraySize) {
	
	// checking if we have removed a symbol, we can remove only one
	bool haveRemovedCharFromTheArray = false;
	//keeping the symbols we have already checked
	char* checkedSymbols = new char[arraySize]();
	int checkedSymbolsIndex = 0;
	//keeping the occurances of the checked symbols
	int* checkedSymbolsOccurances = new int[arraySize]();

	for (size_t i = 0; i < arraySize; i++){

		if (checkedArray[i] == '\0') { break; }
		//keeping the number of repetations of the current symbol
		int currentSymbolRepetation = 0;

		//if we haven't checked it already we check it and we add it to the checked symbols and add its number of occurances
		if (!ContainsInCharArray(checkedSymbols, arraySize, checkedArray[i])) {
			for (size_t j = 0; j < arraySize; j++)
			{
				if (checkedArray[i] == checkedArray[j]) { currentSymbolRepetation++; }
			}
			checkedSymbols[checkedSymbolsIndex] = checkedArray[i];
			checkedSymbolsOccurances[checkedSymbolsIndex] = currentSymbolRepetation;
			checkedSymbolsIndex++;
		}
		
		
	}
	int lastCharRepetation = 0;

	for (size_t i = 0; i < arraySize; i++)
	{
		//breaking if we reach the default initialised value
		if (checkedSymbolsOccurances[i] == 0) { break; }
		if (i != 0)
		{
			// if the occurances of the last symbol aren't equal to the current one's
			if (lastCharRepetation != checkedSymbolsOccurances[i])
			{
				// if the difference between the occurances is too big for the symbol combination to be correct, for example 3 and 5 or 3 and 7
				if (lastCharRepetation != (checkedSymbolsOccurances[i] + 1) && lastCharRepetation != (checkedSymbolsOccurances[i] - 1))
				{
					return false;
				}

				// if we can haven't remove a symbol yet, we remove one
				if (haveRemovedCharFromTheArray == false)
				{
					haveRemovedCharFromTheArray = true;
					// setting the last repetation to the current element, for example 3 2 2 2, we set it to 2
					if (i == 1)
					{
						lastCharRepetation = checkedSymbolsOccurances[i];
					}


					continue;
				}
				// if we try a second time the condition won't be satisfied
				else
				{
					return false;
				}
			}
		}
		// we set the last number of occurances
		lastCharRepetation = checkedSymbolsOccurances[i];
	}
	return 1;
}

int main() {

	// inserting the symbols
	char symbolsCombination[151];
	cin.getline(symbolsCombination, 151);

	//showing if the symbols' combination is correct
	cout<<CorrectSymbolsCombination(symbolsCombination,151);
	
	return 0;
}