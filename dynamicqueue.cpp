#include<iostream>
using namespace std;
template<class t>
class node
{
 public:
  t info;
  node *next;
};
template<class t>
class queues
{
      node<t>*f,*r;
      public:
             queues()
             {
                  f=r=NULL;
             }
           	void insertion(node<t>*);
			t deletion();
			int isempty();
			void clear();
			void display();
			t frontmost();
			t rearmost();
			void count();
			node<t>* createnewnode(t);
};
template <class t>
node<t>* queues<t>:: createnewnode(t add)
{
 node<t>* ptr= new node<t>;
 ptr->info = add;
 ptr->next = NULL;
 return ptr;
}
template <class t>
void queues<t>::insertion(node<t>* temp)
{
	if(f== NULL)
		f=r=temp;
	else 
	{
		r->next=temp;
		r=temp;
	}
}
template <class t>
t queues<t>::deletion()
{
	node<t>* temp;
	t rem;
	temp=f;
	rem=f->info;
	if(f==r)
		f=r=NULL;
	else
		f=f->next;
	delete temp;
	return rem;
}
template<class t>
int queues <t>::isempty()
{
	if(f==NULL)
		return 1;
	else
		return 0;
}
template<class t>
void queues <t>::count()
{
    node<t>* temp;
	int c=0;
	for(temp=f;temp!=NULL;temp=temp->next)
		c++;
	cout<<"count is :"<<c;
}
template<class t>
t queues<t>::frontmost()
{
	t fm;
	fm=f->info;
	return fm;
}
template<class t>
t queues<t> ::rearmost()
{
	t rm;
	rm=r->info;
	return rm;
}
template<class t>
void queues <t>::clear()
{
	node<t>* temp;
	for(temp=f;temp!=NULL;temp=f)
	{
		f=f->next;
		delete temp;
	}
	cout<<"\n cleared";
}
template<class t>
void queues <t>::display()
{

	if(f==NULL)
		cout<<"\nQueue is empty";
	else 
	{
		node<t>* temp;
		for(temp=f;temp!=NULL;temp=temp->next)
		{
			cout<<"\t"<<temp->info;
		}
	}
}

            
int main()
{
     
	queues<int> qu;
	node<int>* nptr;
	char c='y';
	int choice,i,r,e,full;
	while(c=='y'|| c=='Y')
	{
		cout<<"	MAIN MENU"<<endl;
		cout<<"1. To insert a new element"<<endl;
		cout<<"2. To delete a element"<<endl;
		cout<<"3. To check if the queue is empty"<<endl;
		cout<<"4. To clear"<<endl;
		cout<<"5. To display the contents of the queue"<<endl;
		cout<<"6. To find the frontmost element"<<endl;
		cout<<"7. To find the rearmost element"<<endl;
		cout<<"8. TO count"<<endl;
		cout<<"Enter choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1: cout<<"\nEnter the element to be inserted: ";
						cin>>i;
						nptr = qu.createnewnode(i);
						qu.insertion(nptr);
						qu.display();
					break;
			case 2:  e=qu.isempty();
					if(e==1)
						cout<<"\nQueue is empty";
					else 
					{
						r=qu.deletion();
						cout<<"\n "<<r<<" is removed"<<endl;
						qu.display();
					}
					break;
			case 3:
					
					e=qu.isempty();
					if(e==1)
						cout<<"\nQueue is empty";
					else
						cout<<"\nQueue is not empty";
					break;
			case 4: 
					qu.clear();
					cout<<"\n Cleared";
					break;
			case 5:
					qu.display();
					break;
						 	 
					
			case 6:
					r=qu.frontmost();
					cout<<"\n Frontmost element is:"<<r;
					break;
			case 7:
					r=qu.rearmost();
					cout<<"\n Rearmost element is:"<<r;
					break;
			case 8:
					qu.count();
					break;
		}
		cout<<"\n Do you want to continue";
		cin>>c;
	}
     return 0;
}

