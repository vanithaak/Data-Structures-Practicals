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
	else if(r == MAX - 1)
	{
		r = 0; //r++;
		q[r]=i;
	}
	else
	{
	    r++;
		q[r] = i;
	}
	    
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
	if(((f == 0)&&(r==MAX-1)) || (f == r + 1))
		return 1;
	else
		return 0;
}
template<class T>
void queuetype<T>::display()
{
    int i;
	if(f <= r)
	{
	    for(i = 0; i < f; i++)
		   cout<<"-"<<" ";
		for(i = f; i <= r; i++)
		   cout<<" "<<q[i];
		for(i = r + 1; i < MAX; i++)
		   cout<<"-"<<" ";
		   
	}
	else
	{
	    for(i = 0; i <= r; i++)
		   cout<<" "<<q[i];
		for(i = r + 1; i < f; i++)
		   cout<<"-"<<" ";
		for(i = f; i <MAX; i++)
		   cout<<" "<<q[i];
	}

}
template<class T>
int queuetype<T>::count()
{
int cq=0;


  int i;
  if( f<=r)
  {
   for(i=f;i<=r;i++)
      cq++;
   }
  else
  {
    for(i=r;i<=f;i++)
	  cq++;
  }
   
  return cq;
 
}

template<class T>
int queuetype<T>::deletion()
{
  //case 1: cqueue is empty;
  //case 2: single element
  int remove;
  if(f == r)
  {
    remove = q[f];
	f = r = -1;
	return remove;
  }
  else if(f == MAX - 1)
  {
    remove = q[f];
	f = 0;
	return remove;
  }
  else
  {
    remove = q[f];
	f++;
	return remove;
  }
  
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
		cout<<"\n2.To check if the queue is empty";
		cout<<"\n3.To check if the queue is full";
		cout<<"\n4.Display the contents of the queue";
		cout<<"\n5.To see front Most element";
		cout<<"\n6.To see rear Most element";
		cout<<"\n7.To Count the no. of elements";
		cout<<"\n8.To delete an element";
		cout<<"\n9.Clear all elements";
		cout<<"\nEnter your choice(1-9) :";
		cin>>choice;
		switch(choice)
		{
			case 1:full=queue.isfull();
			       if(full==1)
				   cout<<"\nInsertion not possible.CQueue is full";
			       else
			       {
				   cout<<"Enter the element to be inserted :";
				   cin>>i;
				   queue.insert(i);
				   queue.display();
			       }
				break;
			case 2: empty=queue.isempty();
				if(empty==1)
					cout<<"\nCQueue is empty";
				else
					cout<<"\nCQueue is not empty";
				break;
			case 3:full=queue.isfull();
			       if(full==1)
					cout<<"\nCQueue is full";
			       else
					cout<<"\nCQueue is not full";
				break;
			case 4:queue.display();
				break;
			case 5: cout<<"\nThe front most element is :"<<queue.frontmost();
				break;
			case 6: cout<<"\nThe raer most element is :"<<queue.rearmost();
				break;
			case 7: empty=queue.isempty();
				if(empty==1)
					cout<<"\nCQueue is empty";
				else
				    cout<<"\nThe no. of elements are :"<<queue.count();
				break;
			case 8:
			       empty=queue.isempty();
				if(empty==1)
					cout<<"\nCQueue is empty";
				else
				   cout<<"\nElement deleted: "<<queue.deletion();
				break;
			case 9: cout<<"\nThe cqueue is cleared!!";
					queue.clear();
					//queue.display();
				    break;	  	  	  	  
			default:cout<<"Error in input";
		}
		cout<<"\nDo u want to continue(y/n)";
		cin>>c;
	}
}

