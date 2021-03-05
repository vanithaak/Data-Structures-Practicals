#include <iostream>
using namespace std;
template <class T>
class node
{
public:
	T info;
	node *next;
};
template <class T>
class stacktype
{
	node<T>* top;
public:
	stacktype()
	{
		top = NULL;
	}
	void push(node<T>*);
	node<T>* pop();
	bool isempty();
	void display();
	node<T>* createnewnode(int);
	void clear();
};
template <class T>
node<T>* stacktype<T>:: createnewnode(int add)
{
	node<T>* ptr;
	ptr = new node<T>;
	ptr->info = add;
	ptr->next = NULL;
	return ptr;
}
template <class T>
void stacktype<T>:: push(node<T>* nptr)
{
	if (top == NULL)
		top = nptr;
	else
	{
		nptr->next = top;
		top = nptr;
	}
}
template <class T>
node<T>* stacktype<T>:: pop()
{
	node<T>* temp;
	temp = top;
	top = top->next;
	return temp;
}
template <class T>
bool stacktype<T>::isempty()
{
	if (top == NULL)
		return 1;
	else
		return 0;
}
template <class T>
void stacktype<T>::display()
{
	if (isempty())
		cout << "\nCannot display.The stack is empty.";
	else
	{
		cout << "\nContents of the stack: ";
		node<T>* temp;
		for (temp = top;temp != NULL;temp = temp->next)
			cout << temp->info << " ";
	}
}
template <class T>
void stacktype<T>:: clear()
{
	node<T>* temp;
	node<T>* t;
	for (temp = top;temp != NULL;temp = temp->next);
	{
		t = temp;
		delete t;
	}
	top = NULL;
}
int main()
{
	stacktype<int> s;
	int add, e, f, choice;
	char ch = 'y';
	node<int>* nptr;
	while (ch == 'y' || ch == 'Y')
	{
		cout << "------------MAIN MENU-----------:";
		cout << "\n1. Push.";
		cout << "\n2. Pop.";
		cout << "\n3. Isempty?";
		cout << "\n4. Display.";
		cout << "\n5. Clear.";
		cout << "\n   Enter your choice(1-5):";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Enter an integer to be added:";
			cin >> add;
			nptr = s.createnewnode(add);
			s.push(nptr);
			s.display();
			break;
		case 2:
			e = s.isempty();
			if (e == 1)
				cout << "Cannot pop.Underflow.";
			else
			{
				nptr = s.pop();
				cout << nptr->info << " has been deleted.";
				delete nptr;
				s.display();
			}
			break;
		case 3:
			e = s.isempty();
			if (e == 1)
				cout << "Stack is empty!!";
			else
				cout << "Stack is not empty.";
			break;
		case 4:
			s.display();
			break;
		case 5:
			s.clear();
			s.display();
		default:
			cout << "Wrong input.Enter correct choice.";
		}
		cout << "\nDo you want to continue?(Y/N) ";
		cin >> ch;
	}
}

