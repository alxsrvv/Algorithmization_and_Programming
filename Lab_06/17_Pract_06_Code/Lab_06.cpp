#include <iostream>
#include <stdio.h>
#include <conio.h>

void main()
{
	int n = 0;
	std::cout << "This programm can show You all combinations of 5 numbers that contains in 'n'\n" << "Notice, 'n' must be bigger or equal to 5\n" << "Enter n: ";
	std::cin >> n;
	while (n < 5)
	{
		std::cout << "Try to enter another number: ";
		std::cin >> n;
	}
	for (int x5 = 1; x5 <= n - 4; x5++)
		for (int x4 = x5; x4 <= n - 4; x4++)
			for (int x3 = x4; x3 <= n - 4; x3++)
				for (int x2 = x3; x2 <= n - 4 && n - x2 - x3 - x4 - x5 > x2 - 1; x2++)
				{
					int x1 = n - x2 - x3 - x4 - x5;
					std::cout << x1 << " + " << x2 << " + " << x3 << " + " << x4 << " + " << x5 << std::endl;
				}
	_getch();
}//&& n - x2 - x3 - x4 - x5 > x2 - 1