#include<iostream>
#include<conio.h>
#include<string.h>
#include<math.h>
using namespace std;

struct node
{ 
	int data;
	node *next;
};

class stacktype
{
	node *head, *tail;
	public:
		int l;
		stacktype()
		{
			head = NULL;
			tail = NULL;
			l = 0;
		}
		
		void push(char);
		void pop();
		void display();
		int top()
		{
			return head->data;
		}
		void evaluate(char arr[])
		{
			int x,y,z;
			char ch;
			
			for(int  i = 0; arr[i] != ')'; i++)
			{
				ch = arr[i];
				
				if(isdigit(ch))
				{
					push(ch - '0');
					
				}
				else if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
				{
					x = top();
					pop();
					y = top();
					pop();
					switch(ch)
					{
						case '+':{
							z = x + y;
							break;
						}
						case '-':{
							z = x - y;
							break;
						}
						case '*':{
							z = x * y;
							break;
						}
						case '/':{
							z = x / y;
							break;
						}
					    case '$':{
						    z = pow(x,y);
							break;
						}
					    default:cout<<"error in input";
					}
					push(z);
				}
			}
			cout<<"Answer: "<<top();
		}
};

void stacktype::display()
{
	if(l == 0)
	{
		cout<<"Stack is empty";
	}
	else
	{
		
		node *tmp = new node;
		tmp = head;
		
		while(tmp != NULL)
		{
			cout<<"\n\t";	
			cout<<tmp->data<<"\t"<<tmp->next;
			tmp = tmp->next;
		}	
		cout<<"\n\n";
	}
}


void stacktype::push(char d)
{
	if(head == NULL)
	{
		head = new node;
		head->data = d;
		head->next = NULL;
		l++;
	}
	else
	{
		node *tmp = new node;
		tmp->data = d;
		tmp->next = head;
		head = tmp;
		l++; 
	}
}

void stacktype::pop()
{
	if(l == 0)
	{
		cout<<"Stack is already empty. Can't pop now";
	}
	else 
	{
		node *tmp = new node;
		tmp = head;
		head = head->next;
		delete tmp;
		l--;	
	}
}


int main()
{
		stacktype l;
		char arr[10];
		cout<<"Enter expression: ";
		for(int i = 0; i < 10; i++)
		{
			cin>>arr[i];
			if(arr[i] == ')')
			{
				break;
			}
		}
	    l .evaluate(arr);
}

