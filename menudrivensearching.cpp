#include<iostream>
using namespace std;
class searching
{
 int size;
 public:
        void input();
		int linear();
		int binary();
		void display();
};

void searching:: input()
{
   int arr[10], key;
  	do
	{
		cout << "Enter size (size must be between 1-10): ";
		cin >> size;
		if (size > 10 || size < 1)
			cout << " You entered wrong size...\nEnter again...\n";
	}
	while (size > 10 || size < 1);
	cout << "Enter sorted array elements :";
	for (int i = 0;i < size;i++)
		cin >> arr[i];
	cout<<" Enter array element to be searched: ";
	cin>>key;
}

void searching:: linear()
{
    int i;
	int arr[10], key;
	for(i = 0; i < size; i++)
	{
	  if(arr[i] == key)
	  return i;
	}
}

void searching:: binary()
{
   int low, high, mid, key, arr[10];
   low = 0;
   high = size - 1;
   while(low <= high)
     { 
	    mid = (low + high)/2;
		if(key == arr[mid])
		return[mid];
		if(key < arr[mid])
		high = mid - 1;
		else
		low = mid + 1;
	 }
	 return -1;
}
void searching:: display()
{
     int i,key;
     cout<<" Array element "<<key<<" found at: "<<mid;
}
int main()
{
    searching s;
	int choice;
	char ch;
	do
	{
		s.input();
		cout << "Menu\n1.Linear Search\n2.Binary Search";
		cout << "\nEnter your choice:";
		cin >> choice;
		switch (choice)
		{
		case 1:
			s.linear();
			s.display();
			break;
		case 2:
			s.binary();
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

	
  



	      
   
   
     

