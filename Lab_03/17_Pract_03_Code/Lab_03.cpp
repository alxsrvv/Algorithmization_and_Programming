#include <stdio.h> // заголовочный файл input/output
#include <math.h> // заголовочный файл для математических функций
#include <conio.h> // консольный input/output

int main()
{
	float a = 0, b = 0, c = 0, d = 0; // оглашение переменных
	printf("Enter a,b,c,d please:\n");
	scanf_s("%f %f %f %f", &a, &b, &c, &d); // ввод четырех значений

	float y = sqrt(log(c * fabs(2 * d))) + 5 * (cos(a) / acos(-2 * b)); // инициализация y выражением
	printf("Result is %.2f", y); // вывод y

	_getch();
	return 0;
}