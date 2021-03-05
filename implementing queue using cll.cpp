#include<iostream>
using namespace std;
template<class t>
class node
{
  public:
         t info;
		 node *next;
		 node(t x, node *n =NULL)
		 {
		    info =x;
			next = n;
		 }
};

template<class t>
class queueimplementbycll
{
  node<t>*cursor;
  public:
       queueimplementbycll()
	   {
	      cursor = NULL;
	   }
	   void input();
	   int isempty();
	   void insert(t x);
	   t deletion();
	   void count();
	   void display();
	   void clear();
	   
};
template<class t>
void queueimplementbycll<t>::input()
{
  int n;
  t x;
  cout<<"\n Enter number of nodes: ";
  cin>>n;
  for(int i = 0; i < n; i++)
  {
     cout<<"\n Enter info part of node: ";
	 cin>>x;
	 insert(x);
	 display();
  }
}

template<class t>
int queueimplementbycll<t>::isempty()
{
 	if(cursor==NULL)
	return 1;
	else 
	return 0;
}

template<class t>
void queueimplementbycll<t>::insert(t x)
{
  node<t> *temp = new node<t>(x);
  if(isempty())
  {
    cursor = temp;
	cursor->next = cursor;
  }
  else
  {
    temp->next = cursor->next;
	cursor->next = temp;
	cursor = temp;
  }
}

template<class t>
t queueimplementbycll<t>::deletion()
{
  node<t> *temp;
  t x;
  x = cursor->next->info;
  if(cursor->next == cursor)
  {
    delete cursor;
	cursor = NULL;
  }
  else
  {
    temp = cursor->next;
	cursor->next = temp->next;
	delete temp;
  }
  return x;
}

template<class t>
void queueimplementbycll<t>::count()
{
int count=0;
if(!(isempty()))
{

  node<t>*temp;
  temp = cursor->next;
  cout<<"LIST IS: ";
  do
  {
   cout<<temp->info<<"\t";
   temp = temp->next;
   count=count+1;
  }
  while(temp != cursor->next);
  cout<<"\n"<<count;
 }
}

template<class t>
void queueimplementbycll<t>::display()
{
if(!(isempty()))
{

  node<t>*temp;
  temp = cursor->next;
  cout<<"\nLIST IS: ";
  do
  {
   cout<<temp->info<<"\t";
   temp = temp->next;
  }
  while(temp != cursor->next);
 }
}

template<class t>
void queueimplementbycll<t>::clear()
{
t info;
node<t> *next;
info=0;
next=NULL;
}

int main()
{
  queueimplementbycll<int> l1;
  int choice;
  int ele1;
  	 node<int>*temp=NULL;
  char ch = 'y';
  do
  {
    cout<<"************MAIN MENU***********"<<endl;
	cout<<"\n1. To Insert an element! ";
	cout<<"\n2. To Delete an element! ";
	cout<<"\n3. To Count number of elements! ";
	cout<<"\n4. To Display! ";
	cout<<"\n5. To clear! ";
	cout<<"\n Enter choice ";
	cin>>choice;
	switch(choice)
	{
	   case 1:
	          int b;
			  cout<<"\n Enter element to be inserted!!: ";
			  cin>>b;
			  l1.insert(b);
			  l1.display();
			  break;
	   case 2:
	          if(l1.isempty())
			     cout<<"\n List is empty, cannot delete!! ";
			 else
			 {
			 ele1=l1.deletion();
			 cout<<"\n Deleted element is  :"<<ele1<<endl;
			 l1.display();
			 }
			 break;
	   case 3:
	          if(l1.isempty())
			     cout<<"\n List is empty !!";
			 else
			 {
			 cout<<"\n The number of elements in the list are:";
			 l1.count();
			 }
			 break;
	   case 4:
	          if(l1.isempty())
			     cout<<"\n List is empty, nothing to display!! ";
			 else
			 {
			  cout<<"The elements are: ";
			  l1.display();
			  }
			 break;
	   case 5:
	          l1.clear();
			  cout<<"The queue has been cleared!!";
			  break;
			 
	   default:
	         cout<<"\nWRONG CHOICE.";
        }

        cout<<"\nDO YOU WANT TO CONTINUE?(Y/N): ";
        cin>>ch;
    }while(ch=='y'||ch=='Y');
        return 0;

}

