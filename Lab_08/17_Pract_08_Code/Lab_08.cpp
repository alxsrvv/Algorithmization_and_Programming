#include <iostream>
#include <conio.h>
using namespace std;
//GCD - Greatest common divisor

/*
������� ��� ���������� ��� ���� ����� ����������� ������� ������
��������� - 2 ��������������� ����� ��� ���������� ����������� ������ ��������
������ �� ����������, ������� ��������� - ���
*/
void GCD(int n = 0, int m = 0)
{
	if (m % n == 0)
		cout << "\nGreatest common divisor is " << n;
	else
		GCD(m % n, n);
}
/*
������� ��� ������ ������� GCD � ����������� �����������
��������� - 2 ����� ��� ���������� ����������� ������ ��������
������ �� ����������
*/
void right_comb_GCD(int a = 0, int b = 0)
{
	if (a <= b)
		GCD(a, b);
	else
		GCD(b, a);
}
/*
������� ��� ����������� ����� �����
���������� ���
����������: ��������� ��������� �����
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