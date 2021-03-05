#include<iostream>
using namespace std;
template <class T>
class sorting
{
	T arr[40];
	int size;
public:
	void input();
	void bubble();
	void selection();
	void insertion();
	void display();
};
template<class T>
void sorting<T>:: input()
{
	do
	{
		cout << "Enter size (size must be between 1-10): ";
		cin >> size;
		if (size > 10 || size < 1)
			cout << " You entered wrong size...\nEnter again...\n";
	}
	while (size > 10 || size < 1);
	cout << "Enter array elements :";
	for (int i = 0;i < size;i++)
		cin >> arr[i];
}
template<class T>
void sorting<T>:: bubble()
{
	int temp;
	for (int i = 0;i < size; i++)
	{
		for (int j = 0; j < size - 1 - i;j++)
		{
			if (arr[j+1] < arr[j])
			{
				temp = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}
template<class T>
void sorting<T>:: insertion()
{
	int pivot, i, j;
	for (i = 1;i < size;i++)
	{
		pivot = arr[i];;
		j = i - 1;
		while (j >= 0 && arr[j] > pivot)
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = pivot;
	}
}
template<class T>
void sorting<T>:: selection()
{
	int small, pos, temp;
	int i, j;
	for (i = 0;i < size;i++)
	{
		small = arr[i];
		pos = i;
		for (j = i + 1;j < size;j++)
		{
			if (arr[j] < small)
			{
				small = arr[j];
				pos = j;
			}
		}
		temp = arr[i];
		arr[i] = arr[pos];
		arr[pos] = temp;
	}
}
template<class T>
void sorting<T>::display()
{
	cout << "Contents  :";
	for (int i = 0;i < size;i++)
		cout << " " << arr[i];
}
int main()
{
	sorting<int> s;
	int choice;
	char ch;
	do
	{
		s.input();
		cout << "Menu\n1.Bubble sort\n2.Insertion sort\n3.Selection sort";
		cout << "\nEnter your choice(1-3) :";
		cin >> choice;
		switch (choice)
		{
		case 1:
			s.bubble();
			s.display();
			break;
		case 2:
			s.insertion();
			s.display();
			break;
		case 3:
			s.selection();
			s.display();
			break;
		default:
			cout << "\nWrong input...\nEnter correct choice...";
		}
		cout << "\nDo you want to continue?(Y/N)?";
		cin >> ch;
	}
	while (ch == 'y' || ch == 'Y');
	return 0;
}

