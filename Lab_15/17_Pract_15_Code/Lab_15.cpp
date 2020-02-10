#include <iostream>
#include <conio.h>
using namespace std;

struct info
{
	char surname[16];
	char name[16];
	char address[32];
	char section[16];
	int score;
};

int section_compare(const void* sec1, const void* sec2)
{
	return strcmp(((struct info*)sec1)->section, ((struct info*)sec2)->section);
}

int score_compare(const void* score1, const void* score2)
{
	return (((struct info*)score1)->score - ((struct info*)score2)->score);
}

void print_info(const struct info* competitor)
{
	cout << "\nCompetitor :\nSurname : " << competitor->surname
		<< "\nName : " << competitor->name
		<< "\nAddress : " << competitor->address
		<< "\nSection : " << competitor->section
		<< "\nScore : " << competitor->score << endl;
}


void finalists_info(info* array, int finalists_number = 1)
{
	qsort(array, 12, sizeof(info), section_compare);
	int j = 0;
	for (int i = 0; i < 12; i++)
	{
		if (!strcmp(array[i].section, array[i + 1].section))
			continue;
		else
		{
			if (j)
			{
				info* best_competitors = new info[i - j];
				for (int k = i - j; k > 0; k--)
					best_competitors[k - 1] = array[j + k];
				qsort(best_competitors, i - j, sizeof(info), score_compare);
				cout << "\n>----------------------------------------------------------<";
				cout << "\n\nThe passing score in " << array[i].section << " : "
					<< best_competitors[i - j - finalists_number].score << endl
					<< "Applause to finalists at this discipline :\n";
				for (int k = i - j; k > i - j - finalists_number; k--)
					print_info(&best_competitors[k - 1]);
				delete[]best_competitors;
			}
			else
			{
				info* best_competitors = new info[i - j + 1];
				for (int k = i - j; k >= 0; k--)
					best_competitors[k] = array[j + k];
				qsort(best_competitors, i - j + 1, sizeof(info), score_compare);
				cout << "\n>----------------------------------------------------------<";
				cout << "\n\nThe passing score in " << array[i].section << " : "
					<< best_competitors[i - j - finalists_number + 1].score << endl
					<< "Applause to finalists at this discipline :\n";
				for (int k = i - j; k > i - j - finalists_number; k--)
					print_info(&best_competitors[k]);
				delete[]best_competitors;
			}
		}
		j = i;
	}
}

void final()
{
	info competitors[12] = {
		{"Malaev", "Andrew", "avenue Grand Lovetto 43", "Tennis", 15},
		{"Yang", "Larry", "st. Rose park 14", "Tennis", 16},
		{"Travis", "Dorry", "avenue Adams Dene 67", "Cybersport", 145},
		{"Gibson", "Daisy", "alley of Wonder 54/1", "Tennis", 18},
		{"Bridges", "Endy", "st. Parsonage Park Drive 101", "Hackathon", 1244},
		{"Smell", "Alexander", "alley Robertson 51", "Cybersport", 125},
		{"Jackson", "Gordon", "st. Slowy 221", "Hackathon", 2412},
		{"Stickson", "Richard", "st. Blackthorn Common 42", "Cybersport", 135},
		{"Garrison", "Frederick", "alley Wesker Place 64", "Cybersport", 120},
		{"Mescudi", "Chris", "alley Beaulieu Heights 51/2", "Hackathon", 1121},
		{"Dallas", "Morgan", "avenue Parkham Mead 22", "Hackathon", 2445},
		{"Valakas", "Glad", "st. Roflan 228", "Tennis", 17}
	};

	int finalists_number = 0;
	cout << "}------------------{Big tournament began!}------------------{\n\n"
		<< "Enter the number of finalists in every section : ";
	cin >> finalists_number;
	finalists_info(competitors, finalists_number);
}

void main()
{
	final();
	_getch();
}