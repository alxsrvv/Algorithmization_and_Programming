#include <iostream>
#include <conio.h>
using namespace std;

struct stack
{
	int data;
	struct stack* next;
} *top;

void push(int data_to_push)
{
	struct stack* temp;
	temp = new stack();

	if (!temp)
	{
		cout << "\nStack overflow!";
		exit(0);
	}
	
	temp->data = data_to_push;
	temp->next = top;
	top = temp;
}

void pop()
{
	struct stack* temp;
	if (top == NULL)
	{
		cout << "\nStack underflow!";
		exit(0);
	}
	else
	{
		temp = top;
		top = top->next;
		temp->next = NULL;

		free(temp);
	}
}

void output()
{
	struct stack* temp;
	if (top == NULL)
	{
		cout << "Stack underflow!";
		exit(0);
	}
	else
	{
		cout << "\nStack: ";
		temp = top;
		while (temp != NULL)
		{
			cout << temp->data << "  ";
			temp = temp->next;
		}
		cout << endl;
	}
}

void delete_stack()
{
	struct stack* temp;
	temp = top;
	while (top != NULL)
	{
		top = top->next;
		temp->next = NULL;
	}
	free(temp);
	cout << "Stack was fully deleted!";
}

void fill_stack()
{
	cout << "Numbers on the stack must be in the range [-50;50]\n";
	bool x = 0;
	do
	{
		cout << "Enter the number : ";
		short num = 0;
		cin >> num;
		push(num);
		cout << "\nDo You want to enter new number on the stack?\nNo - 0 or Yes - 1   :   ";
		cin >> x;
	} while (x);
	system("cls");
}

void min_to_max_elements_number()
{
	fill_stack();
	output();

	stack *temp = top, *min = top, *max = top;
	while (temp != NULL)
	{
		if (temp->data < min->data)
			min = temp;
		else
		{
			if (temp->data > max->data)
				max = temp;
		}
		temp = temp->next;
	}
	temp = top;
	int counter = 0;
	bool flag = 0;
	while (temp != NULL)
	{
		if (temp->next == min->next || temp->next == max->next)
		{
			flag = !flag;
			temp = temp->next;
			continue;
		}
		if (flag)
			counter++;
		temp = temp->next;
	}
	cout << "Minimum of the stack is " << min->data << '\n';
	cout << "Maximum of the stack is " << max->data << '\n';
	cout << "The number between Min and Max is " << counter << '\n';

	delete_stack();
	output();
}

void main()
{
	min_to_max_elements_number();
}