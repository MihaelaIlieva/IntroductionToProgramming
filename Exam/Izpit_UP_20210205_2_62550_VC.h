#pragma once
// Mihaela Ilieva 62550

bool checkstr( char* text) {
	int strSize = 0;
	while (text[strSize] != '\0') {
		strSize++;
	}
	for (size_t i = 0; i < strSize-1; i++)
	{
		if (text[i] >= 'a' && text[i] <= 'z' &&!(text[i + 1] >= 'A' && text[i + 1] <= 'Z') ) {
			return false;
		}
		if (text[i] >= 'A' && text[i] <= 'Z' && !(text[i+1] >= 'a' && text[i+1] <= 'z') ) {
			return false;
		}
	}
	return true;
}

char* GetWord(char text[]) {
	int textSize = 0;
	while (text[textSize] != '\0') {
		textSize++;
	}
	int wordsStartingWithA = 0;
	int words = 0;
	for (size_t i = 0; i < textSize-1; i++) {
		if ((i == 0 || text[i - 1] == ' ') && (text[i] == 'a' || text[i] == 'A')) {
			wordsStartingWithA++;
		}
		if (i == 0 || text[i - 1] == ' ' && ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'a' && text[i] <= 'z'))) {
			words++;
		}
	}
	char* Awords = new char[10];
	int f = 0;
	while (wordsStartingWithA >= 1) {
		Awords[f] = wordsStartingWithA % 10 + '0';
		wordsStartingWithA = wordsStartingWithA/10;
		f++;
	}
	char* Everywords = new char[10];
	int j = 0;
	while (wordsStartingWithA >= 1) {
		Awords[j] = words % 10 + '0';
		words = words / 10;
		j++;
	}	
	char* answer = new char[20];
	int ansIndex = 0;
	for (int i = f; i >=0 ; i--)
	{
		answer[ansIndex] = Awords[i];
		ansIndex++;
	}
	answer[ansIndex] = ',';
	ansIndex++;

	for (int i = j; i >= 0; i--)
	{
		answer[ansIndex] = Everywords[i];
		ansIndex++;
	}
	return answer;
}

void mySwap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

int AnalyzeNum(long N) {
	long number = N;
	int digitsCount=0;
	while (number >= 1) {
		number / 10;
		digitsCount++;
	}
	int* digits = new int[digitsCount];

	//sorting the array
	for (size_t i = 0; i < digitsCount-1; i++)
	{
		for (size_t j = digitsCount; j >=0; j--)
		{
			if (digits[j] < digits[j - 1]) {
				mySwap(digits[j], digits[j - 1]);
			}
		}
	}
	int middleNumber = 0;
	int middleNumber1 = 0;
	if (digitsCount % 2 != 0) {
		middleNumber = digits[digitsCount / 2];
	}
	if (digitsCount % 2 == 0) {
		middleNumber = digits[digitsCount / 2];
		middleNumber1= digits[digitsCount /2-1];
	}
	int smaller = 0;
	int bigger = 0;

	for (size_t i = 0; i < digitsCount / 2; i++)
	{
		if (digits[i] < middleNumber) {
			smaller++;
		}
	}
	for (size_t i = digitsCount / 2; i < digitsCount-1; i++)
	{
		if (digits[i] > middleNumber) {
			bigger++;
		}
	}

	if (smaller != bigger) {
		return -1;
	}
	else {
		return middleNumber;
	}
}
