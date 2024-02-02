// Mihaela Ilieva fn 62550
#include <iostream>
#include <vector>
using namespace std;

// summing all the numbers' digits
int SumOfAllDigits(int n)
{
	int sum = 0;
	while (n != 0)
	{
		sum = sum + n % 10;
		n = n / 10;
	}
	return sum;
}

// adding the sum of the current number to the sum 
int AddNewNumberDigitsToSum(int n)
{
	if (n <= 0)
	{
		return 0;
	}
	int numberFromCin;
	cin >> numberFromCin;
	//adding only positive digits to the sum
	numberFromCin=numberFromCin > 0 ? numberFromCin: -numberFromCin;
	return SumOfAllDigits(numberFromCin) + AddNewNumberDigitsToSum(n - 1);
}

int main() {
	
	//N is given in the task for it
	int countOfNumbers = 0;

	//checking if the count is valid
	while (countOfNumbers <= 0 || countOfNumbers > 100) {
		cin >> countOfNumbers;
	}

	cout<<AddNewNumberDigitsToSum(countOfNumbers);

	return 0;
}