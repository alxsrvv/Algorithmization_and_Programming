#include <iostream>
#include <conio.h>
using namespace std;
//GCD - Greatest common divisor

/*
функция для нахождения НОД двух чисел рекурсивным методом Эйлера
параметры - 2 отсортированных числа для нахождения наибольшего общего делителя
ничего не возвращает, выводит результат - НОД
*/
void GCD(int n = 0, int m = 0)
{
	if (m % n == 0)
		cout << "\nGreatest common divisor is " << n;
	else
		GCD(m % n, n);
}
/*
функция для вызова функции GCD с правильными параметрами
параметры - 2 числа для нахождения наибольшего общего делителя
ничего не возвращает
*/
void right_comb_GCD(int a = 0, int b = 0)
{
	if (a <= b)
		GCD(a, b);
	else
		GCD(b, a);
}
/*
функция для корректного ввода числа
параметров нет
возвращает: правильно введенное число
*/
int input(void)
{
	cout << "Enter number to find greatest common divisor\nIt must be bigger than zero\nNumber is : ";
	int num = 0;
	while (!(cin >> num) || num < 0)
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
	right_comb_GCD(input(), input());

	_getch();
}