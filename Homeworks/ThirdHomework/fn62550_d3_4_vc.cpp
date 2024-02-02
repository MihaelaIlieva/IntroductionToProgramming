/**
*
* Solution to homework assignment 3
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

#include <iostream>

using namespace std;

// collection for storing all the combinations
char** words;
// the lengths of all words that the words collection contains
int* sizes;
//the index used to add new elements to the words collection
int index = 0;

// getting the number of symbols in the array
int GetArrayNumberOfSymbols(char arrayOfSymbols[]) {
	int i = 0;
	while (arrayOfSymbols[i] != '\0') {
		i++;
	}
	return i;
}
// checking if two arrays are not equal
bool ArraysNotSame(char word[], int wordSize, char otherWord[], int otherWordSize) {
	//checking their sizes, if they are different the arrays cannot be equal to each other
	if (wordSize != otherWordSize) {
		return true;
	}
	// checking if the elements are different
	else {
		for (size_t i = 0; i < wordSize; i++)
		{
			if (word[i] != otherWord[i]) {
				return true;
			}
		}
	}
	return false;
}
// adding a new combination to the words collection if we don't have the same one there already
void AddWordCombination(char word[], int size) {
	// checking if the combination already exists
	for (size_t i = 0; i <=index; i++)
	{
		if (!ArraysNotSame(word, size, words[i], sizes[i])) {
			return;
		}
	}
	// if it doesn't exist in the collection we add it and its occurances, and increase the index
	words[index] = word;
	sizes[index] = size;
	index++;
}
// all the combinations that are made by removing symbols from the "word"
void CombinationsFromRemovingLetters(char word[], int letterCount, int lettersToRemoveCount) {
	if (letterCount == 1) {
		// a copy of the char array in order not to influence other iterations
		char* newWord = new char[letterCount]();
		for (size_t i = 0; i < letterCount; i++)
		{
			newWord[i] = word[i];
		}
		// adding the new combination to the collection
		AddWordCombination(newWord, 1);
		return;
	}
	for (size_t i = 0; i < letterCount; i++)
	{
		// a copy of the char array in order not to influence other iterations
		char* newWord = new char[letterCount]();
		for (size_t i = 0; i < letterCount; i++)
		{
			newWord[i] = word[i];
		}
		// removing an element and shifting all other elements a position back
		for (int t = i; t < letterCount - 1; ++t)
		{
			newWord[t] = newWord[t + 1]; 
		}
		//adding the new combination to the collection
		AddWordCombination(newWord, letterCount - 1);
		CombinationsFromRemovingLetters(newWord, letterCount - 1, lettersToRemoveCount - 1);
	}
}

int main() {

	// inserting the symbols
	char symbols[100];
	cin.getline(symbols, 100);
	// getting the number of symbols and checking if all of them are valid a.k.a are letters
	int countOfSymbols = GetArrayNumberOfSymbols(symbols);
	for (size_t i = 0; i < countOfSymbols; i++)
	{
		if (symbols[i] < 'A' || (symbols[i] > 'Z' && symbols[i] < 'a') || symbols[i]>'z') {
			cout << -1;
			return 0;
		}
	}

	// the collection that we use for storing the combinations of symbols
	words = new char* [10000];
	sizes = new int[100];
	//inserting all the combinations in the words collection and updating the index
	CombinationsFromRemovingLetters(symbols, GetArrayNumberOfSymbols(symbols), GetArrayNumberOfSymbols(symbols));
	//index+1 is equal to the number of combinations
	cout << index + 1 << endl;
	return 0;
}