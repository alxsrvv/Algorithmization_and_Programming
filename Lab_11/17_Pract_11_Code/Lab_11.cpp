#include <iostream>
#include <conio.h>
using namespace std;
#define width 3
#define hight 3

/*
функция для корректного ввода елементов массива
параметр - массив
ничего не возвращает, изменяет массив
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
функция для вывода массива
параметр - массив
ничего не возвращает, выводит массив
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
функция для суммирования столбцов двухмерного массива
параметр - двухмерный массив, массив для записи значений сумм
ничего не возвращает, изменяет нулевой массив записывая суммы столбцов
*/
void mult_of_columns(int(*a)[hight], int* b)
{
	for (int i = 0; i < hight; i++)
		for (int j = 0; j < width; j++)
			b[j] += a[i][j];
}

/*
функция для инициализации массива, ввода, вывода и вывода сумм столбцов двухмерного массива
нет параметров
ничего не возвращает, выводит полученый массив с суммами
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