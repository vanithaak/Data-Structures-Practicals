
#include<iostream>
using namespace std;
template<class t>
class cnode
{
  public:
         t info;
		 cnode *next;
		 cnode(t x, cnode *n =NULL)
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
	      cursor = NULL;
	   }
	    void input();

       void addtofront(t x);
	   void addtoback(t x);
	   void insertxaftery(t x, t y);
	   int isempty();
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
  cnode<t> *temp = new cnode<t>(x);
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
  cnode<t>*temp1;
  cnode<t>*previous;
  if(cursor->next->info==y)
  {
  	 temp->next=cursor->next->next;
     cursor->next->next=temp;
  }
  else if(cursor->info==y)
  {
     addtoback(x);
  }
  
  else
  { 
	
	 
    temp1=cursor->next->next;
  do
  {
    if(temp1->info == y)
	{
      temp->next=temp1->next;
	  temp1->next=temp; 
	}
	else
	temp1 = temp1->next;
  }
  while(temp1 != cursor);
}
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
t cllist<t>::deletefromback()
{
  cnode<t> *temp;
  t x = cursor->info;
  if(cursor->next == cursor)
  {
    delete cursor;
	cursor = NULL;
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
	cursor = NULL;
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
	 prev=curr;
	 curr=curr->next;
	} 
	if(curr->info==x && curr==cursor)
	{
	   prev->next=curr->next;
	   cursor=prev;
	   delete curr;
	}
	 if(curr->info==x)
	 {
	   prev->next = curr->next;
	   delete curr;
	 } 
}


}

template<class t>
cnode<t> * cllist<t>::isinlist(t x)
{
  cnode<t> *temp;
  temp=cursor->next;
  do
  {
    if(temp->info == x)
	    return temp;
	else	
	temp = temp->next;
  }
  while(temp != cursor->next);
  return NULL;
}

template<class t>
cllist<t> cllist<t>::operator+(cllist<t>l1)
{
  cllist<t> l3;
  cnode<t> *temp;
    if(!(isempty()))
  {
  	temp=cursor->next;
	do
	{
	  l3.addtoback(temp->info);
	  temp = temp->next;
	}
	while(temp != cursor->next);
}
  if(!(l1.isempty()))
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
 
 int cllist<t>::isempty()
 {
 	if(cursor==NULL)
	return 1;
	else 
	return 0;
}	 
template<class t>
void cllist<t>::display()
{
if(!(isempty()))
{

  cnode<t>*temp;
  temp = cursor->next;
  cout<<"LIST: ";
  do
  {
   cout<<temp->info<<"\t";
   temp = temp->next;
  }
  while(temp != cursor->next);
 }
}

int main()
{
  cllist<int> l1, l2, l3;
  int choice;
  int ele1;
  	 cnode<int>*temp=NULL;
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
			 temp = l1.isinlist(p);
			 if(temp!=NULL)
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
			 ele1=l1.deletefromfront();
			 cout<<"\n after deletion and deleted element  ::"<<ele1<<endl;
			 l1.display();
			 }
			 break;
	   case 5:
	          if(l1.isempty())
			     cout<<"\n List is empty, cannot delete ";
			 else
			 {
			 ele1=l1.deletefromback();
			 cout<<"\n after deletion and deleted element  ::"<<ele1<<endl;
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
			temp=l1.isinlist(ele);
			if(temp!=NULL)
			{
			 l1.deletenode(ele);
			 l1.display();
			 }
			 else
			 {
			 cout<<"\n No such element ";
			 }
			 }
			 break;
	   case 7:
	        
			 if(l1.isempty())
			    cout<<"\n L1 is empty ";
			 else
			 {
			 cout<<"\n Enter the elements of second CLL: ";
			 l2.input();
			 cout<<"\n FIRST CLL ";
			 cout<<"\n";
			 l1.display();
			 cout<<"\n SECOND CLL ";
			 cout<<"\n";
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
			temp=l1.isinlist(ele);
			 if(temp!=NULL)
			 {
			    cout<<"Element found!!";
				cout<<"\n address  of element ="<<temp;
			}	 
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



