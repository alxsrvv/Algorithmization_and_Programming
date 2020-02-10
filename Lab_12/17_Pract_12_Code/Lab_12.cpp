#include <iostream>
#include <string.h>
#include <conio.h>
using namespace std;
#pragma warning(disable : 4996)

void same_length()
{
	char s[] = "you are big bee";
	cout << "This function can answer, is a string consists only of same length words.\n\n'" << s << "'";
	int f_len = strlen(s), f = 1;
	char* temp_s = strtok(s, " ");
	int len = strlen(temp_s);
	for (int i = 0; i < f_len-len; i += len + 1)
	{
		if (len == strlen(strtok(NULL, " ")))
			continue;
		else
		{
			cout << " consist different length words.";
			f = 0;
			break;
		}
	}
	if (f)
		cout << " consists only of same length words.";
}

void main()
{
	same_length();

	_getch();
}