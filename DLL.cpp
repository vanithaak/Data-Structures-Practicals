#include<iostream>
using namespace std;

template<class T>
class node
{
  public:
   T info;
   node<T> *next,*prev;
   node()
   {
     prev=0;
	 next=0;
   }
   node(T x,node<T> *n=0,node<T> *p=0)
   {
     info=x;
	 next=n;
	 prev=p;
   }
};

template<class T>
class dllist
{
  node<T> *header;
  node<T> *trailer;
  public:
  int l;
  dllist()
  {
    header=trailer=0;
  }
  node<T>* createnewnode(T);
  int isempty();
  void addtohead(T x);
  void addtotail(T x);
  void addtopos(T, T);
  T delfromhead();
  T delfromtail();
  T delfrompos();
  void deletenode(T x);
  node<T> *isinlist(T);
  //void concat(dllist<T> l1);
  void reverse(dllist<T> l1);
  dllist operator +(dllist<T> l1);
  //T input();
  void display();
};

template<class T>
node<T>* dllist<T>::createnewnode(T ele)
{
 node<T> *temp=new node<T>;
 temp->info=ele;
 temp->prev=NULL;
 temp->next=NULL;
}
template<class T>
int dllist<T>::isempty()
{
  if(header==NULL)
    return 1;
  else
    return 0;
}
template<class T>
void dllist<T>::addtohead(T x)
{
  node<T> *temp=new node<T>(x);
  if(isempty())
  {
    header=trailer=temp;
  }
  else
  {
    temp->next=header;
	header->next=temp;
	header=temp;
  }
}
template<class T>
void dllist<T>::addtotail(T x)
{
  node<T> *temp=new node<T>(x);
  if(isempty())
  {
    header=trailer=temp;
  }
  else
  {
    temp->prev=trailer;
	trailer->next=temp;
	trailer=temp;
  }
}

template<class T>
void dllist<T>::addtopos(T d, T pos)
{
 if(pos == 1)
						{
		addtohead(d);
	}
	else 
	{
		node<T> *temp = new node<T>;
		temp->info = d;
		node<T> *cur = new node<T>;
		node<T> *prev = new node<T>;
		cur = header;
		for(int i = 1; i < pos; i++)
		{
			prev = cur;
			cur = cur->next;
		}
		prev->next=temp;
		temp->next=cur;
		l++;
	}
}

template<class T>
T dllist<T>::delfromhead()
{
  
  T x=header->info;
  if(header==trailer)
  {
	delete header;
	header=trailer=0;
  }
  else 
  {
    T x =header->info;
	header=header->next;
	delete(header->prev);
	header->prev=NULL;
  }
  return x;
}

template<class T>
T dllist<T>::delfromtail()
{
   T del;
 node<T> *temp,*temp1;
 for(temp=header;temp->next!=NULL;temp=temp->next)
  {
   if(temp->next->next==NULL)
    {
  	  temp1=temp->next;
	  del=temp1->info;
	  temp->next=NULL;
	  delete temp1;
	  return del;
	}
   } 
}

template<class T>
T dllist<T>::delfrompos()
{
 T ele;
 node<T> *temp,*temp1;
 cout<<"\nEnter the element you want to delete :";
 cin>>ele;
  if(header->info==ele)
  {
   temp=header;
   header=header->next;
   delete temp;
   return 0;
  }
  for(temp=header;temp->next!=NULL;temp=temp->next)
  {
   if(temp->next->info==ele)
   {
     temp1=temp->next;
     temp->next=temp->next->next;
	 delete temp1;
	 return 0;
   }
  }
return -1; 
}

template<class T>
void dllist<T>::display()
{
  node<T> *temp;
  temp=header;
  cout<<"\nCONTENTS OF THE DOUBLLY LINKED LIST FROM HEAD TO TAIL NODE ARE : ";
  while(temp!=0)
  {
    cout<<temp->info<<"\t";
	temp=temp->next;
  }
}

/*template<class T>
T dllist<T>::input()
{
  int n;
  cout<<"\nENTER THE NUMBER(INFO): ";
  cin>>n;
  return n;
}*/

template<class T>
node<T> *dllist<T>::isinlist(T x)
{
  node<T> *temp=NULL;
 for(temp=header;temp!=NULL;temp=temp->next)
  if(temp->info==x)
   return temp;
   
return temp;
}

template<class T>
void dllist<T>::reverse(dllist<T> l1)
{
 	node<T> * temp;
	temp = l1.header;
	while (temp != 0)
	{
		(*this).addtohead(temp -> info);
		temp = temp -> next;
	}
	display();
}

template<class T>
dllist<T> dllist<T>::operator+(dllist<T> l1)
{
  node<T> *temp;
  dllist l3;
  if(!(*this).isempty())
  {
    temp=(*this).header;
	while(temp!=0)
	{
	  l3.addtotail(temp->info);
	  temp=temp->next;
	}
  }
  if(!l1.isempty())
  {
    temp=l1.header;
	while(temp!=0)
	{
	  l3.addtotail(temp->info);
	  temp=temp->next;
	}
  }
  return l3;
}

/*template<class T>
void dllist<T>::concat(dllist<T> l1)
{ 
	node<T> *temp ;
	temp = this->header;
	while(temp->next!= NULL)
	{
  	  temp = temp->next;
	}
	temp->next = l1.header;	     
}*/

int main()
{
    char ch;
    int choice;
    node<int> *nptr;
    dllist<int>l1,l2,l3;
	do 
    {
    cout<<"\n""""THE DOUBLLY LINKED LIST PROGRAM"""" ";
    cout<<"\n------MENU DRIVEN PROGRAM------";
    cout<<"\n1. ADDING TO HEAD POSTION OF LIST: ";
    cout<<"\n2. ADDING TO TAIL POSTION OF LIST: ";
    cout<<"\n3. ADDING TO ANY RANDOM POSITION OF LIST: ";
    cout<<"\n4. DISPLAYING THE LIST: ";
    cout<<"\n5. DELETION OF HEAD POSTION OF LIST: ";
    cout<<"\n6. DELETION OF TAIL POSTION OF LIST: ";
    cout<<"\n7. DELETION AT ANY RANDOM POSTION OF LIST: ";
    cout<<"\n8. REVERSING OF THE LIST: ";
    cout<<"\n9. CONCATENATION OF THE LISTS: ";
    cout<<"\n10. SEARCHING OF ANY ELEMENT IN THE LIST: ";
	cout<<"\n11. LIST IS EMPTY OR NOT";
    cout<<"\nENTER YOUR CHOICE: ";
    cin>>choice;

	switch(choice)
	{
    case 1:
        {
		    int i,n;
            cout<<"\nENTER THE ELEMENT YOU WANT TO ADD AT HEAD POSITION: ";
            cin>>i;
            l1.addtohead(i);
            l1.display();
            break;
        }
    case 2:
        {
            int i;
            cout<<"\nENTER THE ELEMENT YOU WANT TO ADD AT TAIL POSITION: ";
            cin>>i;
            l1.addtotail(i);
            l1.display();
            break;
        }
    case 3:
        {
             int i,pos;
            cout<<"\nENTER THE ELEMENT YOU WANT TO ADD: ";
            cin>>i;
            cout<<"\nAT WHICH POSITION YOU WANT TO ADD AT THE ELEMENT: ";
            cin>>pos;
            l1.addtopos(i,pos);
            l1.display();
            break;
        }
    case 4:
            {
                cout<<"\nTHE FOLLOWING LIST IS: ";
                l1.display();
                break;
            }
    case 5:
        {
		    int e;
		    e=l1.isempty();
			if(e==1)
			cout<<"LIST IS EMPTY..DELETION NOT POSSIBLE!!";
			else 
			{
            cout<<"\nDELETE FROM HEAD POSITION: ";
            l1.delfromhead();
			l1.display();
			}
            break;
        }
    case 6:
        {
		    if(l1.isempty())
	           cout<<"\nLinked List is empty : Nothing to delete!!!";
			else 
			   cout<<"\nThe Deleted element is "<<l1.delfromtail();
			l1.display();
			break;
        }
    case 7:
        {
		    int result;
			if(l1.isempty())
	           cout<<"\nLinked List is empty : Nothing to delete!!!";
			else 
			{
			result=l1.delfrompos();
			if(result==-1)
			 cout<<"The Element you want to delete is not present";
			else 
			   cout<<"\nElement Deleted";
			}
			l1.display();
			break;
        }
    case 8:
        {
            cout << "Reverse of list";
			l2.reverse(l1);
			l2.display();
			break;
        }
    case 9:
        {   
		    
        }
    case 10:
        {
            int ele;
			if(l1.isempty())
	           cout<<"\nLinked List is empty !!!";
			else 
			{
			cout<<"\nEnter the element you want to search for :";
			cin>>ele;
			nptr=l1.isinlist(ele);
			if(nptr!=NULL)
			 cout<<"\nElement found";
			else 
			   cout<<"\nElement not found";
	        }
			break;
        }
		case 11:if(l1.isempty())
	           cout<<"\nLinked List is empty!!!";
			else 
			   cout<<"\nLinked List is not empty";
			break;	  
    default:
        cout<<"\nWRONG CHOICE.";
        }

        cout<<"\nDO YOU WANT TO CONTINUE?: ";
        cin>>ch;
    }while(ch=='y'||ch=='Y');
        return 0;

}

