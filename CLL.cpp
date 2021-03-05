#include<iostream>
using namespace std;
template<class t>
class cnode
{
  public:
         t info;
		 cnode *next;
		 cnode(t x, cnode *n =0)
		 {
		    info =x;
			next = n;
		 }
};

template<class t>
class cllist
{
  cnode<t>*cursor;
  public:
       cllist()
	   {
	      cursor = 0;
	   }
	    void input();
		int isempty()
		{
		   if(cursor == 0)
		      return 1;
		   else
		      return 0;
		}
       void addtofront(t x);
	   void addtoback(t x);
	   void insertxaftery(t x, t y);
	   t deletefromfront();
	   t deletefromback();
	   void deletenode(t x);
	   void display();
	   //void reverse(t x);
	   cnode<t> * isinlist(t x);
	   cllist<t> operator+(cllist<t>l1);
};

template<class t>
void cllist<t>::input()
{
  int n;
  t x;
  cout<<"\n Enter no of nodes: ";
  cin>>n;
  for(int i = 0; i < n; i++)
  {
     cout<<"\n Enter info part: ";
	 cin>>x;
	 addtoback(x);
	 display();
  }
}

template<class t>
void cllist<t>::addtofront(t x)
{
  cnode<t> *temp = new cnode<t>(x);
  if(isempty())
  {
    cursor = temp;
	temp->next = cursor;
  }
  else
  {
    temp->next = cursor->next;
	cursor->next =temp;
  }
}

template<class t>
void cllist<t>::addtoback(t x)
{
  cnode<t> *node = new cnode<t>(x);
  cnode<t> *temp;
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
void cllist<t>::insertxaftery(t x, t y)
{
  cnode<t> *temp = new cnode<t>(x);
  cnode<t> *temp1;
  temp1 = cursor->next;
  do
  {
    if(temp1->info == y)
	{
	  temp->next = temp1->next;
	  temp1->next = temp;
	}
	temp1 = temp1->next;
  }
  while(temp1 != cursor->next);
}

template<class t>
t cllist<t>::deletefromfront()
{
  cnode<t> *temp;
  t x;
  x = cursor->next->info;
  if(cursor->next == cursor)
  {
    delete cursor;
	cursor = 0;
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
t cllist<t>::deletefromback()
{
  cnode<t> *temp;
  t x = cursor->info;
  if(cursor->next == cursor)
  {
    delete cursor;
	cursor = 0;
  }
  else
  {
    temp = cursor->next;
	while(temp->next != cursor)
	{
	  temp = temp->next;
	}
	temp->next = cursor->next;
	delete cursor;
	cursor = temp;
  }
 return x;
}

template<class t>
void cllist<t>::deletenode(t x)
{
  cnode<t> *prev, *curr;
  if((cursor->next == cursor) && (cursor->info = x))
  {
    delete cursor;
	cursor = 0;
  }
  else if(cursor->next->info == x)
  {
    t z = deletefromfront();
  }
  else
  {
    prev = cursor->next;
	curr = prev->next;
	while(curr != cursor && curr->info != x)
	{
	  prev = curr;
	  curr = curr->next;
	}
	if(curr != cursor->next)
	{
	  prev->next = curr->next;
	  if(curr == cursor)
	  {
	    cursor = prev;
		delete curr;
	  }
	}
	else
	{
	  cout<<"\n Element not found ";
	}
  }
}

template<class t>
cnode<t> * cllist<t>::isinlist(t x)
{
  cnode<t> *temp;
  temp = cursor->next;
  do
  {
    if(temp->info == x)
	    return temp;
	temp = temp->next;
  }
  while(temp != cursor->next);
  return 0;
}

template<class t>
cllist<t> cllist<t>::operator+(cllist<t>l1)
{
  cllist<t> l3;
  cnode<t> *temp;
  if(!l1.isempty())
  {
    temp = l1.cursor->next;
	do
	{
	  l3.addtoback(temp->info);
	  temp = temp->next;
	}
	while(temp != l1.cursor->next);
  }
  return l3;
 }
 
template<class t>
void cllist<t>::display()
{
  cnode<t>*temp;
  temp = cursor->next;
  do
  {
   cout<<temp->info<<"\t";
   temp = temp->next;
  }
  while(temp != cursor->next);
}

int main()
{
  cllist<int> l1, l2, l3;
  int choice;
  char ch = 'y';
  do
  {
    cout<<"*********MAIN MENU***********"<<endl;
	cout<<"\n1. Add at front ";
	cout<<"\n2. Add at back ";
	cout<<"\n3. Add x after y ";
	cout<<"\n4. Delete at front ";
	cout<<"\n5. Delete at back ";
	cout<<"\n6. Delete node ";
	cout<<"\n7. Concatenate ";
	cout<<"\n8. Search in list ";
	cout<<"\n Enter choice ";
	cin>>choice;
	switch(choice)
	{
	   case 1:
	          int h;
			  l1.input();
			  cout<<"\n Enter element to add in head: ";
			  cin>>h;
			  l1.addtofront(h);
			  l1.display();
			  break;
	   case 2:
	          int b;
			  cout<<"\n Enter element to add in back: ";
			  cin>>b;
			  l1.addtoback(b);
			  l1.display();
			  break;
	   case 3:
	         int a, p, n;
			 cout<<"\n Ater which element do u want to enter: ";
			 cin>>p;
			 //n = l1.isinlist(p);
			 if(n == 1)
			 {
			 cout<<"\n Enter element to add after y: ";
			 cin>>a;
			 l1.insertxaftery(a, p);
			 l1.display();
			 }
			 else
			   cout<<"the element you are trying to find is not present";
			 break;
	   case 4:
	          if(l1.isempty())
			     cout<<"\n List is empty, cannot delete ";
			 else
			 {
			 l1.deletefromfront();
			 cout<<"\n after deletion ";
			 l1.display();
			 }
			 break;
	   case 5:
	          if(l1.isempty())
			     cout<<"\n List is empty, cannot delete ";
			 else
			 {
			 l1.deletefromback();
			 cout<<"\n after deletion";
			 l1.display();
			 }
			 break;
	   case 6:
	          if(l1.isempty())
			     cout<<"\n List is empty, cannot delete ";
			 else
			 {
			 int ele;
			 cout<<"\n Enter the element you want to delete: ";
			 cin>>ele;
			 l1.deletenode(ele);
			 l1.display();
			 }
			 break;
	   case 7:
	        
			 if(l1.isempty())
			    cout<<"\n L1 is empty ";
			 else
			 {
			 cout<<"\n Enter element for L1: ";
			 l1.input();
			 cout<<"\n Enter the elements of second CLL: ";
			 l2.input();
			 l2.display();
			 l3 = l1 + l2;
			 cout<<"\n Concatenation: ";
			 l3.display();
			 }
			 break;
	   case 8:
	         if(l1.isempty())
			     cout<<"List is empty";
			 else
			 {
			 int ele, e;
			 cout<<"Enter element you want to search: ";
			 cin>>ele;
			 l1.isinlist(ele);
			 if(e == 1)
			    cout<<"Element found!!";
			 else
			    cout<<"Element not found!!";
			 }
			 break;
	   default:
	         cout<<"\nWRONG CHOICE.";
        }

        cout<<"\nDO YOU WANT TO CONTINUE?: ";
        cin>>ch;
    }while(ch=='y'||ch=='Y');
        return 0;

}
	  
			 
			 
	         
			 
			 
	
	
	
  

