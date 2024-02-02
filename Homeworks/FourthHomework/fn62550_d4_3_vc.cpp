/**
*
* Solution to homework assignment 4
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Mihaela Ilieva
* @idnumber 62550
* @task 3
* @compiler VC
*
*/
#include <iostream>

using namespace std;

bool IsGivenValueInValid(int number) {
    return number = 0 ? true : false;
}

int GreatestCommonDivider(int a, int b) {
    if (b == 0)
        return a;
    return GreatestCommonDivider(b, a % b);
}

int main() {
    int numeratorFirst, denominatorFirst, numeratorSecond, denominatorSecond;
    cin >> numeratorFirst;

    cin >> denominatorFirst;



    if (IsGivenValueInValid(denominatorFirst)) {
        cout << -1;
        return 0;
    }
    char operation;
    cin >> operation;

    cin >> numeratorSecond;
    if (operation == '/' && IsGivenValueInValid(numeratorSecond)) {
        cout << -1;
        return 0;
    }
    cin >> denominatorSecond;
    if (IsGivenValueInValid(denominatorSecond)) {
        cout << -1;
        return 0;
    }
    int x = 0;
    int y = 0;
    switch (operation) {
    case '+': x = numeratorFirst * denominatorSecond + numeratorSecond * denominatorFirst; y = denominatorFirst * denominatorSecond; break;
    case '-':x = numeratorFirst * denominatorSecond - numeratorSecond * denominatorFirst; y = denominatorFirst * denominatorSecond; break;
    case '*':x = numeratorFirst * numeratorSecond; y = denominatorFirst * denominatorSecond; break;
    case'/': x = numeratorFirst * denominatorSecond; y = denominatorFirst * numeratorSecond; break;
    default: cout << -1; return 0; break;
    }

    int greatestCommondDivider = GreatestCommonDivider(x, y);
    cout << x / greatestCommondDivider << " " << y / greatestCommondDivider;

    return 0;

}