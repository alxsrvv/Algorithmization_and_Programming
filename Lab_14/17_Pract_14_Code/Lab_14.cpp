#include <iostream>
#include <conio.h>
using namespace std;
#define num 64

void console_output(FILE* DATA)
{
	cout << "Data from file:\n";
	int val = 0;
	for (int i = 0; i < num; i++)
	{
		fscanf_s(DATA, "%i", &val);
		cout << val << ' ';
	}
	cout << endl;
	fseek(DATA, 0, SEEK_SET);
}

void negative_zeros_positive(void)
{
	FILE* F1; fopen_s(&F1, "D:\\data.txt", "rb");
	console_output(F1);
	FILE* F2; fopen_s(&F2, "D:\\out.txt", "w");

	int var = 0; unsigned short zeros = 0;
	for (int i = 0; i < num; i++)
	{
		fscanf_s(F1, "%i", &var);
		if (var < 0)
			fprintf(F2, "%i ", var);
		else
			if (var == 0)
				zeros++;
	}
	fseek(F1, 0, SEEK_SET);

	for (;zeros > 0; zeros--)
		fprintf(F2, "%i ", 0);

	for (int i = 0; i < num; i++)
	{
		fscanf_s(F1, "%i", &var);
		if (var > 0)
			fprintf(F2, "%i ", var);
	}
	fclose(F1);
	fclose(F2);

	fopen_s(&F2, "D:\\out.txt", "r");
	console_output(F1);
	fclose(F2);
}

void main()
{
	negative_zeros_positive();
	_getch();
}