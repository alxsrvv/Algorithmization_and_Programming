#include <iostream>
#include <stdio.h>
#include <conio.h>

int main()
{
	int D = 0;
	std::cout << "Enter day from 1 to 365: ";
	std::cin >> D;
	if (D >= 1 && D <= 365)
	{
		int M = 1;
		while (D > 31)
		{
			switch (M)
			{
			case 1: case 3: case 5: case 7: case 8: case 10: D -= 31; break;
			case 4: case 6: case 9: case 11: D -= 30; break;
			case 2: D -= 28; break;
			}
			M++;
		}
		printf("You choose the right day!\nMonth: %d\nDay: %d", M, D);
	}
	else printf("\nIncorrect input!");

	_getch();
	return 0;

}