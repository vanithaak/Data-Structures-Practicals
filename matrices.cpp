#include<iostream.h>
#include<process.h>
template<class t>
class DIAGONAL
{
	t *a;
	int size;
public:
	DIAGONAL(int S1)
	{
		size = S1;
		a = new t[size];
	}
	void STORE(int i, int j, t x);
	t RETRIEVE(int i, int j);
};
template<class t>
void DIAGONAL<t>::STORE(int i, int j, t x)
{
	if ((i < 1) || (j < 1) || (i > size) || (j > size))
	{
		cout << "INVALID INDEX (T__T)" << endl;
		return;
	}
	else if (i == j)
		a[i - 1] = x;
	else if (x != 0)
	{
		cout << "X MUST BE ZERO (T__T)" << endl;
		return;
	}
}
template<class t>
t DIAGONAL<t>::RETRIEVE(int i, int j)
{
	if ((i < 1) || (j < 1) || (i > size) || (j > size))
	{
		cout << "INVALID INDEX (T__T)" << endl;
		exit(1);
	}
	else if (i == j)
		return a[i - 1];
	else
		return 0;
}
template<class t>
class LOWTRI
{
	t *a;
	int size;
public:
	LOWTRI(int S1)
	{
		size = S1 * (S1 + 1) / 2;
		a = new t[size];
	}
	void STORE(int i, int j, t x);
	t RETRIEVE(int i, int j);
};
template<class t>
void LOWTRI<t>::STORE(int i, int j, t x)
{
	if ((i < 1) || (j < 1) || (i > size) || (j > size))
	{
		cout << "INVALID INDEX (T__T)" << endl;
		return;
	}
	else if (i >= j)
		a[(i*(i-1)/2)+(j-1)] = x;
	else if (x != 0)
	{
		cout << "X MUST BE ZERO (T__T)" << endl;
		return;
	}
}
template<class t>
t LOWTRI<t>::RETRIEVE(int i, int j)
{
	if ((i < 1) || (j < 1) || (i > size) || (j > size))
	{
		cout << "INVALID INDEX (T__T)" << endl;
		exit(1);
	}
	else if (i >= j)
		return a[(i*(i-1)/2)+(j-1)];
	else
		return 0;
}
template<class t>
class UPTRI
{
	t *a;
	int size;
public:
	UPTRI(int S1)
	{
		size = S1 * (S1 + 1) / 2;
		a = new t[size];
	}
	void STORE(int i, int j, t x);
	t RETRIEVE(int i, int j);
};
template<class t>
void UPTRI<t>::STORE(int i, int j, t x)
{
	if ((i < 1) || (j < 1) || (i > size) || (j > size))
	{
		cout << "INVALID INDEX (T__T)" << endl;
		return;
	}
	else if (j >= i)
		a[(j*(j-1)/2)+(i-1)] = x;
	else if (x != 0)
	{
		cout << "X MUST BE ZERO (T__T)" << endl;
		return;
	}
}
template<class t>
t UPTRI<t>::RETRIEVE(int i, int j)
{
	if ((i < 1) || (j < 1) || (i > size) || (j > size))
	{
		cout << "INVALID INDEX (T__T)" << endl;
		exit(1);
	}
	else if (j >= i)
		return a[(j*(j-1)/2)+(i-1)];
	else
		return 0;
}
template<class t>
class SYMMETRIC
{
	t *a;
	int size;
public:
	SYMMETRIC(int S1)
	{
		size = S1 * (S1 + 1) / 2;
		a = new t[size];
	}
	void STORE(int i, int j, t x);
	t RETRIEVE(int i, int j);
};
template<class t>
void SYMMETRIC<t>::STORE(int i, int j, t x)
{
	if ((i < 1) || (j < 1) || (i > size) || (j > size))
	{
		cout << "INVALID INDEX (T__T)" << endl;
		return;
	}
	else if (i >= j)
		a[(i*(i-1)/2)+(j-1)] = x;
	else if (x != 0)
	{
		cout << "X MUST BE ZERO (T__T)" << endl;
		return;
	}
}
template<class t>
t SYMMETRIC<t>::RETRIEVE(int i, int j)
{
	if ((i < 1) || (j < 1) || (i > size) || (j > size))
	{
		cout << "INVALID INDEX (T__T)" << endl;
		exit(1);
	}
	else if (i >= j)
		return a[(i*(i-1)/2)+(j-1)];
	else
		return a[(j*(j-1)/2)+(i-1)];
}
int main()
{
	int x, i, j, size, choice;
	char ch;
	cout << "\nENTER THE SIZE: " << endl;
	cin >> size;
	DIAGONAL<int>D(size);
	LOWTRI<int>L(size);
	UPTRI<int>U(size);
	SYMMETRIC<int>S(size);
	do
	{
		cout << "\n----------MAIN MENU------------" << endl;
		cout << "1. DIAGONAL" << endl;
		cout << "2. LOWERTRIANGULAR" << endl;
		cout << "3. UPPERTRIANGUKAR" << endl;
		cout << "4. SYMMETRICTRIANGULAR" << endl;
		cout << "   enter your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "\n Enter the elements: " << endl;
			for (i = 1; i <= size;i++)
				for (j = 1;j <= size;j++)
				{
					cout << "\n";
					cin >> x;
					D.STORE(i, j, x);
				}
			for (i = 1;i <= size;i++)
			{
				for (j = 1;j <= size;j++)
				{
					cout << D.RETRIEVE(i, j) << "\t";
				}
				cout << "\n";
			}
			break;
		case 2:
			cout << "\n Enter the elements: " << endl;
			for (i = 1; i <= size;i++)
				for (j = 1;j <= size;j++)
				{
					cout << "\n";
					cin >> x;
					L.STORE(i, j, x);
				}
			for (i = 1;i <= size;i++)
			{
				for (j = 1;j <= size;j++)
				{
					cout << L.RETRIEVE(i, j) << "\t";
				}
				cout << "\n";
			}
			break;
		case 3:
			cout << "\n Enter the elements: " << endl;
			for (i = 1; i <= size;i++)
				for (j = 1;j <= size;j++)
				{
					cout << "\n";
					cin >> x;
					U.STORE(i, j, x);
				}
			for (i = 1;i <= size;i++)
			{
				for (j = 1;j <= size;j++)
				{
					cout << U.RETRIEVE(i, j) << "\t";
				}
				cout << "\n";
			}
			break;
		case 4:
			cout << "\n Enter the elements: " << endl;
			for (i = 1; i <= size;i++)
				for (j = 1;j <= size;j++)
				{
					cout << "\n";
					cin >> x;
					S.STORE(i, j, x);
				}
			for (i = 1;i <= size;i++)
			{
				for (j = 1;j <= size;j++)
				{
					cout << S.RETRIEVE(i, j) << "\t";
				}
				cout << "\n";
			}
			break;
		default:
			cout << "\n Wrong choice -__-";
		}
		cout << "\n do you want to continue?(y/n): ";
		cin >> ch;
	}
	while (ch == 'y' || ch == 'Y');
}

