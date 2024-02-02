/**
*
* Solution to homework assignment 4
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

// wanted function
bool KnightMove(int movesAllowed, int knightRow, int knightCol, int numberOfRows, int numberOfCols, int finalRow,int finalCol) {
	if (knightRow==finalRow && knightCol==finalCol)
	{
		return true;
	}
	if (movesAllowed<=0)
	{
		return false;
	}

	if (knightRow<=numberOfRows && knightCol<=numberOfCols && knightRow>=0 && knightCol>=0)
	{

		//Move top left
		if (!KnightMove(movesAllowed-1,knightCol-1,knightRow-2,numberOfRows,numberOfCols,finalRow,finalCol))
		{
			//Move left top
			if (!KnightMove(movesAllowed - 1, knightCol -2, knightRow - 1, numberOfRows, numberOfCols, finalRow, finalCol))
			{
				//Move left bottom
				if (!KnightMove(movesAllowed - 1, knightCol -2, knightRow + 1, numberOfRows, numberOfCols, finalRow, finalCol))
				{
					//Move bottom left
					if (!KnightMove(movesAllowed - 1, knightCol - 1, knightRow + 2, numberOfRows, numberOfCols, finalRow, finalCol))
					{
						//Move bottom right
						if (!KnightMove(movesAllowed - 1, knightCol + 1, knightRow + 2, numberOfRows, numberOfCols, finalRow, finalCol))
						{
							//Move right bottom
							if (!KnightMove(movesAllowed - 1, knightCol + 2, knightRow + 1, numberOfRows, numberOfCols, finalRow, finalCol))
							{
								//Move right top
								if (!KnightMove(movesAllowed - 1, knightCol + 2, knightRow -1, numberOfRows, numberOfCols, finalRow, finalCol))
								{
									//Move top right
									if (!KnightMove(movesAllowed - 1, knightCol + 1, knightRow - 2, numberOfRows, numberOfCols, finalRow, finalCol))
									{
										return false;
									}
								}
							}
						}
					}
				}
			}
		}
		return true;

	}
	else
	{
		return false;
	}
}

int main()
{
	//(N,M)ª(3,200], (p, q, p1, q1)ª(0, 200], kª(0, 30]

	int numberOfRows, numberOfCols;
	cin >> numberOfRows;
	if (numberOfRows <= 3 || numberOfRows > 200) {
		cout << -1;
		return 0;
	}
	cin >> numberOfCols;
	if (numberOfCols <= 3 || numberOfCols > 200) {
		cout << -1;
		return 0;
	}
	numberOfRows--;
	numberOfCols--;

	int knightRow, knightCol;
	cin >> knightRow;
	if (knightRow <= 0 || knightRow > 200) {
		cout << -1;
		return 0;
	}
	cin >> knightCol;
	if (knightCol <= 0 || knightCol > 200) {
		cout << -1;
		return 0;
	}
	int finalRow, finalCol;
	cin >> finalRow;
	if (finalRow <= 0 || finalRow > 200) {
		cout << -1;
		return 0;
	}
	cin >> finalCol;
	if (finalCol <= 0 || finalCol > 200) {
		cout << -1;
		return 0;
	}
	int movesAllowed;
	cin >> movesAllowed;
	if (movesAllowed <= 0 || movesAllowed > 30) {
		cout << -1;
		return 0;
	}
	cout << KnightMove(movesAllowed, knightRow, knightCol, numberOfRows, numberOfCols, finalRow, finalCol);

	return 0;
}
