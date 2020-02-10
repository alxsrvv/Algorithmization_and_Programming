#include <iostream>
#include <cstdlib>
#include <time.h>
#include <conio.h>
using namespace std;

/*
������� ��� ����������� ����� ����������� ��������� �������
��� ����������
����������: ������������� �������� ����� �������
*/
int number_of_elements(void)
{
	cout << "Enter a number of elements in random array : ";
	int n = 0;
	while (!(cin >> n) || n <= 0)
	{
		cout << "Try correct number!\n";
		cin.clear();
		cin.ignore();
		fflush(stdin);
	}
	return n;
}

/*
������� ��� ���������� ����������� ������� ���������� �������������� ���������� � ���������� [0, 50]
���������: ������ ��� ����������, ������ �������
������ �� ����������, �������� ������ �������� ��� ���������� ����������
*/
void fill_array(int* arr, int arr_len = 50)
{
	srand(time(NULL));
	for (int i = 0; i < arr_len; i++)
		arr[i] = rand() % 50;
}

/*
������� ��� ������ ����������� �������
���������: ������ ��� ����������, ������ �������
������ �� ����������, ������� ���������� ������
*/
void output(int* arr, int arr_len = 50)
{
	cout << "\nRandom array is { ";
	for (int i = 0; i < arr_len; i++)
		cout << arr[i] << " ";
	cout << "}\n";
}

/*
������� ��� ���������� �� ����������� �������� ��������� ������� � ������� ��������� ���������� �����
���������: ������ ��� ����������, ������ �������
������ �� ����������, ��������� ������
*/
void shell_sort(int* arr, int arr_len = 50)
{
	for (int interval = (arr_len/2) - ((arr_len/2)%2); interval > 1; interval = (interval/2) - ((interval/2)%2))
		for (int i = interval; i < arr_len; i += 2)
		{
			int tmp = arr[i], j = 0;
			for (j = i; j >= interval && arr[j - interval] > tmp; j -= interval)
				arr[j] = arr[j - interval];
			arr[j] = tmp;
		}
	cout << "\n*Magic algorithm happened*\n";
}

/*
������� ��� ��������, ����������, ������ � ���������� �� ����������� �������� ��������� ������� � ������� ��������� ���������� �����
���������: ������ �������
������ �� ����������
*/
void array_func(int arr_len = 50)
{
	int* rand_array = new int[arr_len];
	fill_array(rand_array, arr_len);
	output(rand_array, arr_len);

	shell_sort(rand_array, arr_len);
	
	output(rand_array, arr_len);
}

void main()
{
	cout << "This function can sort in ascending order odd elements in random array by Shellsort method\n\n";
	array_func(number_of_elements());

	_getch();
}