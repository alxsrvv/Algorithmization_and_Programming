#include <stdio.h> // ������������ ���� input/output
#include <math.h> // ������������ ���� ��� �������������� �������
#include <conio.h> // ���������� input/output

int main()
{
	float a = 0, b = 0, c = 0, d = 0; // ��������� ����������
	printf("Enter a,b,c,d please:\n");
	scanf_s("%f %f %f %f", &a, &b, &c, &d); // ���� ������� ��������

	float y = sqrt(log(c * fabs(2 * d))) + 5 * (cos(a) / acos(-2 * b)); // ������������� y ����������
	printf("Result is %.2f", y); // ����� y

	_getch();
	return 0;
}