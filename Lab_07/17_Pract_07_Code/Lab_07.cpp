#include <iostream>
#include <bitset>
#include <conio.h>

using namespace std;
/*
void binary_cout(int num = 0)
{
	bitset<32> binary(num);
	cout << binary << '\n';
}
*/
/*
функци€ дл€ корректного ввода числа
параметр - верхн€€ граница числа
возвращает: правильно введенное число
*/
unsigned input(unsigned limit = 0)
{
	unsigned num = 0;
	while (!(cin >> num) || num < 0 || num > limit)
	{
		cout << "Try correct number!\n";
		cin.clear();
		cin.ignore();
		fflush(stdin);
	}
	return num;
}
void main()
{
	cout << "This program works with binary numbers\n\n";
	cout << "Enter the start number X, such 0 <= X <= 429496729\nX : ";
	unsigned x = input(429496729); // граница дл€ беззнакового целочисленного значени€
	cout << "Enter the number of digits N, such 0 <= N <= 32\nN : ";
	unsigned n = input(32);
	cout << "Enter the position P, such 0 <= P <= 32\nP : ";
	unsigned p = input(32);
	//binary_cout(x);
	unsigned y = x & (-1 << (n + p)) | ((x & ((1 << p) - 1)) << n);
	//binary_cout(y);
	cout << "\nThe new number is exactly " << y << endl;

	_getch();
}