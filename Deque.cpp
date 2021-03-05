#include <iostream>
#include <iomanip>
using namespace std;
template <class t>
class node
{
public:
	t info;
	node<t> *next, *prev;
	node()
	{
		next = 0;
		prev = 0;
	}
	node(t x, node<t> *n = 0, node<t> *p = 0)
	{
		info = x;
		next = n;
		prev = p;
	}
};
template <class t>
class deque
{
	node<t>* front;
	node<t>* rear;
	int size;
public:
	deque()
	{
		front = rear = 0;
	}
	void insertfront(t x);
	void insertback(t x);
	t removefront();
	t removeback();
	int isempty();
	int count();
	void display();
	void clear();
	t frontmost();
	t rearmost();
};
template <class t>
int deque<t>::isempty()
{
	if (front == 0)
		return 1;
	else
		return 0;
}
template <class t>
void deque<t>::insertfront(t x)
{
	node<t> *temp;
	temp = new node<t> (x);
	if (isempty())
	{
		front = rear = temp;
	}
	else
	{
		temp -> next = front;
		front -> prev = temp;
		front = temp;
	}
}
template <class t>
void deque<t>::insertback(t x)
{
	node<t> *temp;
	temp = new node<t> (x);
	if (isempty())
	{
		front = rear = temp;
	}
	else
	{
		rear -> next = temp;
		temp -> prev = rear;
		rear = temp;
	}
}
template<class t>
int deque<t>::count()
{
	int count = 0;
	node<t> *temp;
	for (temp = front; temp != NULL; temp = temp->next)
		count++;
	return count;
}
template <class t>
t deque<t>::removefront()
{
	t x;
	if (front == rear)
	{
		x = front -> info;
		delete front;
		front = rear = 0;
	}
	else
	{
		x = front -> info;
		front = front -> next;
		delete (front -> prev);
		front -> prev = 0;
	}
	return x;
}
template <class t>
t deque<t>::removeback()
{
	t x;
	if (front == rear)
	{
		x = rear -> info;
		delete rear;
		front = rear = 0;
	}
	else
	{
		x = rear -> info;
		rear = rear -> prev;
		delete (rear -> next);
		rear -> next = 0;
	}
	return x;
}
template <class t>
void deque<t>::display()
{
	node<t> *temp;
	temp = front;
	cout << "\nContents of Double Ended queue List from head to tail are!!! : ";
	while (temp != 0)
	{
		cout << setw(5) << temp -> info;
		temp = temp -> next;
	}
}
template <class t>
t deque<t>::frontmost()
{
	t fm;
	fm = front->info;
	return fm;
}
template <class t>
t deque<t>::rearmost()
{
	t rm;
	rm = rear->info;
	return rm;
}
template<class t>
void deque<t>::clear()
{
	node<t> *temp;
	/*           temp=front->next;
	do
	{
	temp=temp->next;
	}while(temp!=front->next);
	front=rear=0;
	*/
	rear = NULL;
	while (front != NULL)
	{
		temp = front;
		front = front->next;
		delete(temp);
	}
	size = 0;
}
int main()
{
	deque<int> l1;
	int choice, el, d, e;
	char ch = 'Y';
	cout << "*-------------MENU-------------*\n";
	cout << "1. Insert a node at Beginning\n";
	cout << "2. Insert a node at End\n";
	cout << "3. Delete from Beginning\n";
	cout << "4. Delete from End\n";
	cout << "5. Count the number of elements\n";
	cout << "6. Display Frontmost element\n";
	cout << "7. Display Rearmost element\n";
	cout << "8. Check for the emptyness of queue\n";
	cout << "9. Clear the list\n";
	while (ch == 'y' || ch == 'Y')
	{
		cout << "Enter choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1 :
		{
			cout << "Enter the element you want to insert in beginning: ";
			cin >> el;
			l1.insertfront(el);
			l1.display();
			break;
		}
		case 2:
		{
			cout << "Enter the element you want to insert in end: ";
			cin >> el;
			l1.insertback(el);
			l1.display();
			break;
		}
		case 3:
		{
			d = l1.isempty();
			if (d == 1)
			{
				cout << "\nSorry but the queue is empty :( ";
			}
			else
			{
				l1.removefront();
				l1.display();
			}
			break;
		}
		case 4:
		{
			d = l1.isempty();
			if (d == 1)
			{
				cout << "\nSorry but the queue is empty :( ";
			}
			else
			{
				l1.removeback();
				l1.display();
			}
			break;
		}
		case 5:
		{
			d = l1.isempty();
			if (d == 1)
			{
				cout << "\nSorry but the queue is empty :( ";
			}
			else
			{
				e = l1.count();
				cout << "\nThe total number of elements are : " << e << endl;
				l1.display();
			}
			break;
		}
		case 6:
		{
			d = l1.isempty();
			if (d == 1)
			{
				cout << "\nSorry but the queue is empty :( ";
			}
			else
			{
				e = l1.frontmost();
				cout << "\nThe frontmost element is : " << e << endl;
				l1.display();
			}
			break;
		}
		case 7:
		{
			d = l1.isempty();
			if (d == 1)
			{
				cout << "\nSorry but the queue is empty :( ";
			}
			else
			{
				e = l1.rearmost();
				cout << "\nThe rearmost element is : " << e << endl;
				l1.display();
			}
			break;
		}
		case 8:
		{
			d = l1.isempty();
			if (d == 1)
			{
				cout << "\n Queue is empty!";
			}
			else
			{
				cout << "\n Queue is not empty!!";
			}
			break;
		}
		case 9:
		{
			l1.clear();
			cout << "\nThe Queue is cleared !" << endl;
			break;
		}
		default:
			cout << "\nInput Invalid :( ";
		}
		cout << "\nDo you want to continue ?(y/n)";
		cin >> ch;
	}
}

