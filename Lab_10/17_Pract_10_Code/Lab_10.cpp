#include <iostream>
#include <conio.h>
using namespace std;

/*
функция для корректного ввода елементов массива
параметр - масив
ничего не возвращает, изменяет массив
*/
void input(int* a)
{
	for (int i = 0; i < 10; i++)
	{
		cout << "Enter A[" << i << "] : ";
		while (!(cin >> a[i]))
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
параметр - масив
ничего не возвращает, выводит массив
*/
void output(int* a)
{
	cout << "\nYour array is { ";
	for (int i = 0; i < 10; i++)
		cout << a[i] << " ";
	cout << "}\n\n";
}

/*
функция для подсчета елементов в массиве до первого отрицательного числа, входящие в промежуток [x,y]
параметр - масив
возвращает: sum - количество элементов
*/
int elements(int* a)
{
	cout << "Enter x - down limit for numbers in array\nX : ";
	int x = 0;
	cin >> x;
	cout << "Enter y - top limit for numbers in array, which is bigger than x\nY : ";
	int y = 0;
	cin >> y;
	while (y < x)
	{
		cout << "y is smaller than x. Try one more time.";
		cin >> y;
	}
	int sum = 0;
	for (int i = 0; i < 10; i++)
	{
		if (a[i] < 0)
			break;
		if (a[i] >= x && a[i] <= y)
			sum += 1;
	}
	return sum;
}

/*
функция для инициализации массива, ввода, вывода и подсчета елементов в массиве до первого отрицательного числа, входящие в промежуток [x,y]
нет параметров
ничего не возвращает, выводит количество элементов
*/
void my_array(void)
{
	cout << "This program can enter values for array and count elements before a first negative number,\nwhich are bigger than x and smaller than y!\n\n";
	int arr[10];
	
	input(arr);

	output(arr);

	cout << '\n' << elements(arr) << " elements in array before a negative number, which are bigger than x and smaller than y.";
}

void main()
{
	my_array();

	_getch();
}