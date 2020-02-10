#include <iostream>
#include <cmath>
#include <conio.h>
using namespace std;
/*
Функція для коректного введення чисел
Параметрів немає
Повертає: введене корректне число
*/
double input(void)
{
	double n = 0;
	while (!(cin >> n))
	{
		cout << "Try correct number!\n";
		cin.clear();
		cin.ignore();
		fflush(stdin);
	}
	return n;
}
/*
Функція для рекурсивного підрахунку членів ряду Тейлора, з зупинкою при досягненні члену меншого за похибку
Параметри: x, допустима похибка, попередній член ряду, кількість членів
Повертає: сумму ряду, окрім першого члену
*/
double temp_sum(double x, double error, double prior_term, int& i)
{
	double term = prior_term * -((pow(9, i + 1)) * x * x) / (2 * (pow(9, i) + 3) * (i + 1) * (2 * i + 1));
	if (fabs(term) < error)
		return term;
	return term + temp_sum(x, error, term, ++i);
}
/*
Функція повертає сумму ряду та рахує кількість необхідних членів, для досягнення заданої точності
Параметри: x, допустима похибка, кількість членів
Повертає: сумму ряду
*/
double series(double x, double error, int& steps)
{
	steps = 0;
	double sum = 1 + temp_sum(x, error, 1, steps);
	return sum;
}

void main()
{
	double x_begin = 0;
	double x_end = 0;
	double x_delta = 0;
	double e = 0;
	cout << "Taylor series of cos^3(x)\n\nUse keyboard [k] or file [f] input?\nChoose: ";
	char kf = 'k';
	cin >> kf;
	if (kf == 'k') // keyboard input
	{
		cout << "\nPlease, enter the range\nx_begin is ";
		x_begin = input();
		cout << "x_end is ";
		x_end = input();
		cout << "Enter step and allowable error\nStep is ";
		x_delta = input();
		cout << "Error is ";
		e = input();
	}
	if (kf == 'f') //txt file input
	{
		FILE* input;
		char inp[32] = "";
		while (1)
		{
			cout << "\nEnter the name of txt file to read: ";
			cin >> inp;
			if ((fopen_s(&input, inp, "r")) != NULL)
				cout << "Cannot read this file.\n";
			else
				break;
		}
		fscanf_s(input, "%lf", &x_begin);
		fscanf_s(input, "%lf", &x_end);
		fscanf_s(input, "%lf", &x_delta);
		fscanf_s(input, "%lf", &e);
		fclose(input);
	}

	FILE* output; // txt file output
	char otp[32] = "";
	cout << "\nEnter the name of txt file to write the result: ";
	cin >> otp;
	fopen_s(&output, otp, "w");
	cout << "\n\n|   x   |  series(x) |    y(x)    |    error   | steps |";
	fprintf(output, "|   x   |  series(x) |    y(x)    |    error   | steps |");

	while (x_begin <= x_end)
	{
		int i = 0;
		double fx = pow(cos(x_begin), 3);
		double result = series(x_begin, e, i);
		double mistake = fabs(fx - result);
		printf("\n| %5.2f | %10.6f | %10.6f | %10.6f | %5d |", x_begin, result, fx, mistake, i+1);
		fprintf(output, "\n| %5.2f | %9.6f | %10.6f | %10.6f | %5d |", x_begin, result, fx, mistake, i+1);
		x_begin += x_delta;
	}
	fclose(output);
	_getch();
}