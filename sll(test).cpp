#include<iostream>
#include<iomanip>
using namespace std;

template<class T>
class node
{
    public:
	T data;
	node *next;
	node *prev;
};

template<class T>
class lists
{
    public:
	    node <T>*head; 
		node <T>*tail;
		int l;
		lists()
		{
			l = 0;
			head = NULL;
			tail = NULL;
		}
        node<T> *create_new_node(T p);
		void create_new_list(node<T> *);
		void search(T);
		void disp_list();
		void add_to_pos(T,T);
		void del_tail();		
        void concat(lists);
};

template<class T>
node<T>* lists<T>:: create_new_node(T i)
		{
		    node<T> *newptr;
		    newptr=new node<T>;
		    newptr->data=i;
		    newptr->next=NULL;
		    return(newptr);
		}
	
template<class T>  
void lists<T> :: create_new_list(node<T>*newptr)
		{
		    node<T> *temp;
		    temp=head;
		    head=newptr;
		    newptr->next=temp;
		}
template<class T>
void lists<T>::search(T data)
		{
			int i = 1;
			int count = 0;
			node<T> *tmp;
			tmp = head;
			while(tmp != NULL)
			{
				if(tmp->data == data)
				{
					cout<<endl<<data<<" FOUND AT INDEX: "<<i<<endl;
					count++;
				}
				tmp = tmp->next;
				i++;
			}
			if(count == 0)
			{
				cout<<endl<<data<<"NOT FOUND IN THE LIST."<<endl;
			}
		}
template<class T>
void lists<T>::add_to_pos(T d,T pos)
{
 node<T>* temp = head;
 node<T>* prev = head;
  node<T>* temp1 = head;
 if(pos == 1)
 {
  temp1->next = head;
  head = temp1;
  }
  else
  {
    for(int i=1; i<pos-1; i--)
	{
	 prev = prev->next;
	 }
	 for(int i = 1; i < pos; i++)
	 {
	 temp = temp->next;
	 }
	 temp1->next = temp;
	 prev->next = temp1;
	 }

}
template<class T>
void lists<T>::del_tail()
{
	node<T> *tmp;
	tmp = tail;
	tail = tail->prev;
	tail->next = NULL;
	l--;
	delete tmp;
}

template<class T>
void lists<T>::concat(lists l1)
{ 
	node<T> *tmp ;
	tmp = this->head;
	while(tmp->next!= NULL)
	{
  	  tmp = tmp->next;
	}
	tmp->next = l1.head;	  
}

template<class T>
void lists<T>::disp_list()
{
	cout<<"\n";
	node<T> *tmp;
	tmp = head;
	while(tmp != NULL)
	{
	    // cout<<endl<<tmp->data<<"\n\n";
		//cout<<tmp->data<<"\t"<<setw(8)<<tmp->prev<<"\t"<<tmp->next;
		cout<<tmp->data<<"\t";
		tmp = tmp->next;

	}
}
int main()
{
    char ch;
    int choice;
    lists<int>l,l1;
    do 
    {
    cout<<"\nTHE LINKED LIST PROGRAM: ";
    cout<<"\nMENU DRIVEN PROGRAM: ";
    cout<<"\n1. ADDING TO ANY RANDOM POSITION OF LIST.";
    cout<<"\n2. DELETION OF TAIL POSTION OF LIST.";
	cout<<"\n3. DISPLAYING THE LIST: ";
    cout<<"\n4. CONCATENATION OF THE LISTS ";
    cout<<"\n5. SEARCHING OF ANY ELEMENT IN THE LIST";
    cout<<"\nENTER YOUR CHOICE: ";
    cin>>choice;

	switch(choice)
	{
 
    case 1:
        {
            int item,pos;
            cout<<"\nENTER THE ELEMENT YOU WANT TO ADD: ";
            cin>>item;
            cout<<"\nAT WHICH POSITION YOU WANT TO ADD AT THE ELEMENT: ";
            cin>>pos;
            l.add_to_pos(item,pos);
            cout<<"\nADDED.";
            break;
        }
		
	case 2:
        {
           cout<<"\nDELETE FROM TAIL POSITION: ";
		   l.del_tail();
            break;
        }
		
    case 3:
            {
                cout<<"\nTHE FOLLOWING LINKED LIST IS: ";
                l.disp_list();
                break;
            }
   
    case 4:
        {   
		    
            cout<<"\nCONCATENATION OF LISTS: ";
            l1.concat(l);
            break;
        }
    case 5:
        {
            int item;
            cout<<"\nENTER ELEMENT YOU WANT TO SEARCH: ";
            cin>>item;
            cout<<"\nSEARCHING OF ELEMENT IN LIST: ";
            l.search(item);
        }

    default:
        cout<<"\nWRONG CHOICE.";
        }

        cout<<"\nDO YOU WANT TO CONTINUE?: ";
        cin>>ch;
    }while(ch=='y'||ch=='Y');
        return 0;

}

