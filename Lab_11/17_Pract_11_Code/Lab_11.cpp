#include <iostream>
#include <conio.h>
using namespace std;
#define width 3
#define hight 3

/*
������� ��� ����������� ����� ��������� �������
�������� - ������
������ �� ����������, �������� ������
*/
void input(int(* a)[hight])
{
	for (int i = 0; i < hight; i++)
		for (int j = 0; j < width; j++)
		{
			cout << "Enter A[" << i << "][" << j << "] : ";
			while (!(cin >> a[i][j]))
			{
				cout << "Try correct number!\n";
				cin.clear();
				cin.ignore();
				fflush(stdin);
			}
		}
}

/*
������� ��� ������ �������
�������� - ������
������ �� ����������, ������� ������
*/
void output(int(*a)[hight])
{
	cout << "\nYour array is :\n\n";
	for (int i = 0; i < hight; i++)
	{
		for (int j = 0; j < width; j++)
			cout << a[i][j] << "  ";
		cout << "\n\n";
	}
}

/*
������� ��� ������������ �������� ����������� �������
�������� - ���������� ������, ������ ��� ������ �������� ����
������ �� ����������, �������� ������� ������ ��������� ����� ��������
*/
void mult_of_columns(int(*a)[hight], int* b)
{
	for (int i = 0; i < hight; i++)
		for (int j = 0; j < width; j++)
			b[j] += a[i][j];
}

/*
������� ��� ������������� �������, �����, ������ � ������ ���� �������� ����������� �������
��� ����������
������ �� ����������, ������� ��������� ������ � �������
*/
void my_array()
{
	int arr[hight][width];
	input(arr);

	int final_arr[width] = {};
	mult_of_columns(arr, final_arr);

	output(arr);

	cout << "Sums of columns are :\n\n";
	for (int i = 0; i < width; i++)
		cout << final_arr[i] << "  ";
}

void main()
{
	my_array();

	_getch();
}