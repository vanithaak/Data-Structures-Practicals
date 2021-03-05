#include<iostream.h>
#include<conio.h>
const int SIZE = 10;
template <class S>
class stackk
{
	int s[SIZE];
	int top;
public:
	void push(int);
	int pop();
	int isempty();
	int isfull();
	void display();
	stackk()
	{
		top = -1;
	}
};
template <class S>
void stackk<S>::push(int p)
{
	top++;
	s[top] = p;
}
template <class S>
int stackk<S>::pop()
{
	int d;
	d = s[top];
	top--;
	return(d);
}
template <class S>
void stackk<S>::display()
{
	if (top == -1)
		cout << " Stack is empty!! ";
	else
	{
		cout << " Elements in Stack from top are ";
		for (int i = top; i >= 0; i--)
			cout << s[i] << " ";
		cout << endl;
	}
}
template <class S>
int stackk<S>::isempty()
{
	int e;
	if (top == -1)
	{
		cout << endl << " Stack is empty!! " << endl;
		return(1);
	}
	else
	{
		cout << " Stack is not empty!! " << endl;
		return(0);
	}
}
template <class S>
int stackk<S>::isfull()
{
	int f;
	if (top == SIZE - 1)
	{
		cout << " Stack is full!! " << endl;
		return(1);
	}
	else
	{
		cout << endl << " Stack is not full ;___; " << endl;
		return 0;
	}
}
int main()
{
	stackk<int> st;
	char c = 'y';
	int choice, f, p, d, e;
	while (c == 'y' || c == 'Y')
	{
		cout << endl << "----------------MAIN MENU------------------" << endl;
		cout << "1. Push onto the stack " << endl;
		cout << "2. Pop from the stack " << endl;
		cout << "3. Check if stack is empty " << endl;
		cout << "4. Check if stack is full" << endl;
		cout << "5. Display " << endl;
		cout << "Enter your choice";
		cin >> choice;
		switch (choice)
		{
		case 1:
			f = st.isfull();
			if (f == 1)
				cout << " Stack is full insertion is not possible";
			else
			{
				cout << " Enter thr element to be pushed ";
				cin >> p;
				st.push(p);
				st.display();
			}
			break;
		case 2:
			e = st.isempty();
			if (e == 1)
				cout << " Deletion not possible " << endl;
			else
			{
				d = st.pop();
				cout << "\n" << d << "has been deleted";
				st.display();
			}
			break;
		case 3:
			e = st.isempty();
			if (e == 1)
				cout << " \nStack is empty!! ";
			else
				cout << "\nStack is not empty ";
			break;
		case 4:
			f = st.isfull();
			break;
		case 5:
			st.display();
		default:
			cout << " Error: Enter correct input ";
		}
		cout << " Do you want to continue(y or n) ";
		cin >> c;
	}
}


