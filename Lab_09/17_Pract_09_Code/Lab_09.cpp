#include <iostream>
#include <conio.h>
using namespace std;
void main()
{
	int n = 20;
	double factorial = 1;

	for (int i = 1; i <= n; i++)
		factorial *= i;
	cout << "Factorial of " << n << " is " << factorial << endl;
	_getch();
}