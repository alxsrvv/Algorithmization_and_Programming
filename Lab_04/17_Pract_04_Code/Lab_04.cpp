#include <iostream>
#include <math.h> 
#include <conio.h>

int main()
{
	float x = 0, y = 0, R = 0; // ���� ����������
	std::cout << "Enter x:\n"; 
	std::cin >> x;
	std::cout << "Enter y:\n";
	std::cin >> y;
	std::cout << "Enter radius R:\n";
	std::cin >> R;

	if ((x * x + y * y) > (R * R)) // �� ��������� �����
		std::cout << "The point is outside the circle\n";
	else
	{
		std::cout << "The point is inside the circle ";
		if (x < y) // ��� ������ y=x
			std::cout << "and above the line";
		else // � ������ �������
			std::cout << "and under the line\nSo the point is in the area";
	}
	_getch();
	return 0;
}
