#include<iostream.h>
template<class T>
class node
{
public:
	T info;
	node<T>*next;
	node(T x)
	{
		info = x;
		next = NULL;
	}
};
template <class t>
class sll
{
public:
	node<t>* head;
	sll()
	{
		head = NULL;
	}
	node<t>* createnode(t x);
	void insertion(node<t>*temp, int position);
	t removefromend(int position);
	node<t>* search(t y);
	void addtotail(t x);
	sll<t>  concatenate(sll<t>ob1);
	int display();
	int isempty()
	{
		if (head == NULL)
			return 1;
		else
			return 0;
	}
};
template<class t>
node<t>* sll<t>:: createnode(t x)
{
	node<t>*temp = new node<t>(x);
	return temp;
}
template<class t>
void sll<t>::insertion(node<t>*temp, int position)
{
	node<t>*temp1 = head;
	node<t>*previous = head;
	if (position == 1)
	{
		temp->next = head;
		head = temp;
	}
	else
	{
		for (int i = 1;i < position - 1;i++)
		{
			previous = previous->next;
		}
		for (int i = 1;i < position;i++)
		{
			temp1 = temp1->next;
		}
		temp->next = temp1;
		previous->next = temp;
	}
}
template<class t>
t sll<t>:: removefromend(int position)
{
	t x;
	node<t>*temp = head;
	if (position == 1)
	{
		if (head->next == NULL)
		{
			x = temp->info;
			head = NULL;
		}
		else
		{
			x = temp->info;
			head = head->next;
		}
		delete temp;
		return x;
	} 
		else	
		{
		for (int i = 1;i <= position;i++)
		{
			temp = temp->next;
		}
		x = temp->info;
		delete temp;
		return x;
	}
}
template<class t>
node<t>* sll<t>:: search(t y)
{
	node<t>*temp = head;
	while (temp != NULL)
	{
		if (y == temp->info)
			break;
		else
			temp = temp->next;
	}
	if (temp == NULL)
	{
		cout << "\n Element not found!! ";
		return temp;
	}
	else
	{
		cout << "\n Element found!! ";
		return temp;
	}
}
template<class t>
void sll<t>::addtotail(t x)
{
	node<t>*temp = new node<t>(x);
	node<t>*curr;
	if (head == NULL)
	{
		head = temp;
	}
	else
	{
		curr = head;
		while (curr->next != NULL)
		{
			curr = curr->next;
		}
		curr->next = temp;
	}
}
template<class t>
sll<t> sll<t>:: concatenate(sll<t>ob1)
{
	sll<t>ob3;
	node<t>*temp1 = head;
	node<t>*temp2 = ob1.head;
	while (temp1 != NULL)
	{
		ob3.addtotail(temp1->info);
		temp1 = temp1->next;
	}
	while (temp2 != NULL)
	{
		ob3.addtotail(temp2->info);
		temp2 = temp2->next;
	}
	return ob3;
}
template<class t>
int sll<t>::  display()
{
	int count = 0;
	node<t>*temp = head;
	cout << "\n Linked list consists of: ";
	while (temp != NULL)
	{
		cout << temp->info << "  ";
		count++;
		temp = temp->next;
	}
}
int main()
{
	char c = 'y';
	sll<int>ob;
	sll<int>ob1;
	sll<int>ob3;
	node<int>*temp = NULL;
	int element1;
	int x;
	int ch;
	int y;
	int a = 1;
	int count1 = 0;
	int count2 = 0;
	int pos;
	cout << "\n Enter elements for linked list  1: " << endl;
	while (c == 'y')
	{
		cout << "\n Enter element: ";
		cin >> x;
		count1++;
		temp = ob.createnode(x);
		ob.insertion(temp, a);
		cout << "\n Do you want to add more elements? (y/n) ";
		cin >> c;
	}
	c = 'y';
	cout << "\n First  linked list: ";
	cout << "\n";
	ob.display();
	cout << "\n Enter elements for second linked list: " << endl;
	while (c == 'y')
	{
		cout << "\n Enter element: ";
		cin >> x;
		temp = ob1.createnode(x);
		count2++;
		ob1.insertion(temp, a);
		cout << "\n Do you want to add more elements ?(y/n) ";
		cin >> c;
	}
	c = 'y';
	cout << "\n Second  linked list:  ";
	cout << "\n";
	ob1.display();
	while (c == 'y')
	{
		cout << "\n********MENU DRIVEN*********" << endl;
		cout << "\n 1.Insert element at ith position ";
		cout << "\n 2.Remove element from end ";
		cout << "\n 3.Search for element ";
		cout << "\n 4.Concatenate ";
		cout << "\n Please enter your choice:" << endl;
		cin >> ch;
		switch (ch)
		{
		case 1:
		{
			cout << "\n Enter element: ";
			cin >> x;
			cout << "\n Where to insert the element, list 1 or list 2(1/2)?";
			cin >> y;
			if (y == 1)
			{
				cout << "\n Enter the position for inserting the element  (1- " << ++count1 << "): ";
				cin >> pos;
				if (pos > count1)
				{
					cout << "\n No such position exists! ";
					break ;
				}
				else
				{
					temp = new node<int>(x);
					ob.insertion(temp, pos);
					//cout << "\n Present list: ";
					cout << "\n";
					ob.display();
					break;
				}
			}
			if (y == 2)
			{
				cout << "\n Enter the position for inserting the element  (1- " << ++count2 << "): ";
				cin >> pos;
				if (pos > count2)
				{
					cout << "\n No such position exists! ";
					break ;
				}
				else
				{
					temp = new node<int>(x);
					ob1.insertion(temp, pos);
					//cout << "\n Present list: ";
					cout << "\n";
					ob1.display();
					break;
				}
			}
		}
		case 2:
		{
			cout << "\n From where to remove the element  list 1 or list 2(1/2)?";
			cin >> y;
			if (y == 1)
			{
				int element = ob.removefromend(1);
				count1--;
				cout << "\n Popped element : " << element ;
				break;
			}
			if (y == 2)
			{
				int element = ob1.removefromend(1);
				count2--;
				cout << "\n Popped element:  " << element ;
				break;
			}
		}
		case 3:
		{
			cout << "\n";
			cout << "\n From where to search (list1 /list 2)?   ";
			cin >> y;
			if (y == 1)
			{
				int n = ob.isempty();
				if (n == 1)
				{
					cout << "\n Empty!!!";
					break;
				}
				else
				{
					cout << "\n Enter element to be searched:   ";
					cin >> element1;
					temp = ob.search(element1);
					if (temp != NULL)
						cout << "\n   " << temp->info;
					break;
				}
			}
			if (y == 2)
			{
				int n = ob1.isempty();
				if (n == 1)
				{
					cout << "\n Empty!!!";
					break;
				}
				else
				{
					cout << "\n Enter element to be searched:   ";
					cin >> element1;
					temp = ob1.search(element1);
					if (temp != NULL)
						cout << "\n  " << temp->info;
					break;
				}
			}
		}
		case 4:
		{
			ob3 = ob.concatenate(ob1);
			cout << "\n";
			cout << "\n Concatenated list is: ";
			cout << "\n";
			ob3.display();
			break;
		}
		}
		cout << "\n Do you wish to continue?(y/n)   ";
		cin >> c;
	}
	int n;
	for (int i = 0;i < count1;i++)
	{
		if (!(ob.isempty()))
		{
			n = ob.removefromend(1);
		}
	}
	for (int i = 0;i < count2;i++)
	{
		if (!(ob1.isempty()))
		{
			n = ob1.removefromend(1);
		}
	}
	for (int i = 0;i < count1 + count2;i++)
	{
		if (!(ob3.isempty()))
		{
			n = ob3.removefromend(1);
		}
	}
	return 0;
}

