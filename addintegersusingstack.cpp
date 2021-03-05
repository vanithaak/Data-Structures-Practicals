#include<iostream>
using namespace std;
class stackdemo
{
	int st[10];
	int top;
public:
	stackdemo()
	{
		top = -1;
	}
	void push(int);
	int pop();
	void display();
	int isfull();
	int isempty();
	stackdemo add(stackdemo ob1);
};
void stackdemo::push(int e)
{
	top++;
	st[top] = e;
}
int stackdemo::pop()
{
	int rem;
	if (isempty())
	{
		cout << "\nlist is empty";
		return(-1);
	}
	else
	{
		rem = st[top--];
		return rem;
	}
}
void stackdemo:: display()
{
	cout << "\nthe stack is :";
	for (int i = 0;i <= top;i++)
		cout << "\n" << st[i];
}
stackdemo stackdemo::add(stackdemo ob2)
{
	int carry = 0;
	stackdemo ob;
	int x, y;
	while (!isempty() || !ob2.isempty())
	{
		if (!isempty())
			x = pop();
		else
			x = 0;
		if (!ob2.isempty())
			y = ob2.pop();
		else
			y = 0;
		carry = carry + x + y;
		ob.push(carry % 10);
		carry = carry / 10;
	}
	if (carry != 0)
		ob.push(carry) ;
	return ob;
}
int stackdemo::isempty()
{
	if (top == -1)
		return 1;
	else
		return 0;
}
int main()
{
	stackdemo ob1, ob2, ob3;
	int a, n, b;
	cout << "\nenter n ";
	cin >> n;
	cout << " enter first " << n << " digits\n ";
	for (int i = 0;i < n;i++)
	{
		cin >> a;
		ob1.push(a);
	}
	ob1.display();
	cout << "\n enter n";
	cin >> n;
	cout << "\nenter second " << n << "  digits\n ";
	for (int i = 0;i < n;i++)
	{
		cin >> b;
		ob2.push(b);
	}
	ob2.display();
	ob3 = ob1.add(ob2);
	ob3.display();
	return 0;
}

