#include<iostream.h>
#include<conio.h>

const int MAX=10;
template<class T>
class queuetype
{
       T q[MAX];
       int f,r;
       public:
	   
	   queuetype()
	   {
	   		f=r=-1;
		}
			
       void insert(int);
       int deletion();
       int isempty();
       int isfull();
       void display();
       void clear()
	   {
	   f=r=-1;
	   }
	   
       T frontmost()
	   { return q[f];
	   }
       T rearmost()
	   {return q[r];
	   }
       int count();
       
};

template<class T>
void queuetype<T>::insert(int i)
{
	if(r==-1)
	{
		f=r=0;
		q[r]=i;
	}
	else
	{
		r++;
		q[r]=i;
	}
}
template<class T>
int queuetype<T>::deletion()
{
	T temp;
	if(f==r)
	{
	      temp=q[f];
	      f=r=-1;
	}
	else
	{
		temp=q[f];
		f++;
	}
	return temp;

}
template<class T>
int queuetype<T>::isempty()
{
	if((f==-1)&&(r==-1))
		return 1;
	else
		return 0;
}
template<class T>
int queuetype<T>::isfull()
{
	if(r==MAX-1)
		return 1;
	else
		return 0;
}
template<class T>
void queuetype<T>::display()
{
	if(r==-1)
		cout<<"\n  Queue is empty";
	else
	{
		cout<<"\n  Contents of the queue are :";
		for(int i=f;i<=r;i++)
			cout<<q[i]<<" ";
	}

}
template<class T>
int queuetype<T>::count()
{
int cq=0;


  int temp;
  for(temp=f;temp<=r;temp++)
   cq++;
   
  return cq;
 
}
    

int main()
{
	queuetype<int> queue;
	char c='y';
	int choice,i,r,empty,full;
	
	while(c=='y'||c=='Y')
	{
		cout<<"\nMain Menu";
		cout<<"\n1.To insert a new element";
		cout<<"\n2.To remove an element";
		cout<<"\n3.To check if the queue is empty";
		cout<<"\n4.To check if the queue is full";
		cout<<"\n5.Display the contents of the queue";
		cout<<"\n6.To see top Most element";
		cout<<"\n7.To see rear Most element";
		cout<<"\n8.To Count the no. of elements";
		cout<<"\n9.Clear all elements";
		cout<<"\nEnter your choice(1-9) :";
		cin>>choice;
		switch(choice)
		{
			case 1:full=queue.isfull();
			       if(full==1)
				   cout<<"\nInsertion not possible.Queue is full";
			       else
			       {
				   cout<<"Enter the element to be inserted :";
				   cin>>i;
				   queue.insert(i);
				   queue.display();
			       }
				break;
			case 2:empty=queue.isempty();
			       if(empty==1)
				 cout<<"\nQueue is empty..Deletion not possible";
			       else
			       {
				 r=queue.deletion();
				 cout<<"\n"<<r<<" has been deleted"<<"\n";
				 queue.display();
			       }
				break;
			case 3: empty=queue.isempty();
				if(empty==1)
					cout<<"\nQueue is empty";
				else
					cout<<"\nQueue is not empty";
				break;
			case 4:full=queue.isfull();
			       if(full==1)
					cout<<"\nQueue is full";
			       else
					cout<<"\nQueue is not full";
				break;
			case 5:queue.display();
				break;
			case 6: cout<<"\nThe top most element is :"<<queue.frontmost();
				break;
			case 7: cout<<"\nThe raer most element is :"<<queue.rearmost();
				break;
			case 8: empty=queue.isempty();
				if(empty==1)
					cout<<"\nQueue is empty";
				else
				    cout<<"\nThe no. of elements are :"<<queue.count();
				break;
			case 9: cout<<"\nThe queue is cleared!!";
					queue.clear();
				break;	  	  	  	  
			   	   
			default:cout<<"Error in input";
		}
		cout<<"\nDo u want to continue(y/n)";
		cin>>c;
	}
}

