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
		void count();
		void search(T);
		void reverse();
		void add_to_head(T);
		void disp_list();
		void add_to_tail(T);
		void add_to_pos(T,T);
		void del_head();
		void del_tail();
		void del_from_pos(T);
		void del_num(T);		
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
void lists<T> :: count()
		{
		    int i=0;
		    node<T> *temp;
		    for(temp=head;temp!=NULL;temp=temp->next)
                i++;
                cout<<"\nNO OF NODES: "<<i;
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
void lists<T>::reverse()
		{
	      node<T> *curr;
	      node<T> *prev;
	      node<T> *nextn;
		  
	      nextn = head->next;

	     if(nextn==NULL||curr==NULL)
		 {
		   return;
		 }
		 else 
		 {
		   node<T> *prev=NULL;
		   node<T> *curr=NULL;
		   node<T> *nextn=NULL;
		   curr = head;
		   while(curr!=NULL)
		   { 
		     nextn = curr->next;
			 curr->next=prev;
			 prev=curr;
			 curr=nextn;
		   }
		   head = prev;
		 }
	}

template<class T>
void lists<T>::add_to_head(T d)
{
	if(head == NULL)
	{
		head = new node<T>;
		head->data = d;
		head->next = NULL;
		head->prev = NULL;
		tail = head;
		l++;
	}
	else
	{
		node<T> *tmp;
		tmp->data = d;
		tmp->next = head;
		tmp->prev = NULL;
		head->prev = tmp;
		head = tmp;
		l++;
	}
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

template<class T>
void lists<T>::add_to_tail(T d)
{
	if(tail == NULL)
	{
		cout<<"NO LIST FOUND. CAN'T ADD.";
	}
	else
	{
		node<T> *tmp;
		tmp->data = d;
		tmp->next = NULL;
		tmp->prev = tail;
		tail->next = tmp;
		tail = tmp;
		l++;
	}
}

template<class T>
void lists<T>::add_to_pos(T d,T pos)
{
    if (pos==1)
    {
      add_to_head(d);
	}
	else if (pos==l)
	{
		add_to_tail(d);
	}
	else
    {
	node<T> *tmp;
	tmp->data=d;
	node<T>*pre;
	node<T>*cur;
	cur=head;
	for (int i=1;i<=pos-1;i++)
	{
		   pre=cur;
		   cur=cur->next;
	}
	pre->next=tmp;
	tmp->next=cur;
	l++;
    }
}

template<class T>
void lists<T>::del_head()
{
	node<T> *tmp;
	tmp = head;
	head = head->next;
	head->prev = NULL;
	l--;
	delete tmp;
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
void lists<T>::del_from_pos(T pos)
{
	if(pos == 1)
	{
		del_head();
	}

	else if(pos == l)
	{
		del_tail();
	}

	else
	{
		node<T> *tmp;

		tmp = head;
		for(int i = 1; i < pos; i++)
		{
			tmp = tmp->next;
		}

		node<T> *n;
		node<T> *p;
		n = tmp->next;
		p = tmp->prev;

		n->prev = p;
		p->next = n;

		delete tmp;
		l--;
	}
}

template<class T>
void lists<T>::del_num(T d)
{
	while(head->data == d)
	{
		del_head();
	}

	while(tail->data == d)
	{
		del_tail();
	}
	node<T> *tmp;
	tmp = head;
	int size = l;
	for(int i = 1; i < l; i++)
	{
		tmp = tmp->next;
		if(tmp->data == d)
		{
			node<T> *n;
			node<T> *p;
			n = tmp->next;
			p = tmp->prev;

			n->prev = p;
			p->next = n;

			l--;
		}
	}
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

int main()
{
    char ch;
    int choice;
    lists<int>l,l1;
    do 
    {
    cout<<"\nTHE LINKED LIST PROGRAM: ";
    cout<<"\nMENU DRIVEN PROGRAM: ";
    cout<<"\n1. ADDING TO HEAD POSTION OF LIST.";
    cout<<"\n2. ADDING TO TAIL POSTION OF LIST.";
    cout<<"\n3. ADDING TO ANY RANDOM POSITION OF LIST.";
    cout<<"\n4. DISPLAYING THE LIST: ";
    cout<<"\n5. DELETION OF HEAD POSTION OF LIST.";
    cout<<"\n6. DELETION OF TAIL POSTION OF LIST.";
    cout<<"\n7. DELETION AT ANY RANDOM POSTION OF LIST.";
    cout<<"\n8. REVERSING OF THE LIST ";
    cout<<"\n9. CONCATENATION OF THE LISTS ";
    cout<<"\n10. SEARCHING OF ANY ELEMENT IN THE LIST";
    cout<<"\n11. TOTAL NUMBER OF NODES: ";
    cout<<"\nENTER YOUR CHOICE: ";
    cin>>choice;

	switch(choice)
	{
    case 1:
        {
            int item;
            cout<<"\nENTER THE ELEMENT YOU WANT TO ADD AT HEAD POSITION: ";
            cin>>item;
            l.add_to_head(item);
            cout<<"\nADDED.";
            break;
        }
    case 2:
        {
            int item;
            cout<<"\nENTER THE ELEMENT YOU WANT TO ADD AT TAIL POSITION: ";
            cin>>item;
            l.add_to_tail(item);
            cout<<"\nADDED.";
            break;
        }
    case 3:
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
    case 4:
            {
                cout<<"\nTHE FOLLOWING LINKED LIST IS: ";
                l.disp_list();
                break;
            }
    case 5:
        {
            cout<<"\nDELETE FROM HEAD POSITION: ";
            l.del_head();
            break;
        }
    case 6:
        {
           cout<<"\nDELETE FROM TAIL POSITION: ";
		   l.del_tail();
            break;
        }
    case 7:
        {
            int pos;
            cout<<"\nENTER THE POSITION YOU WANT TO DELETE FROM: ";
            cin>>pos;
            cout<<"\nDELETE FROM ANY RANDOM POSITION: ";
		    l.del_from_pos(pos);
		    break;
        }
    case 8:
        {
            cout<<"\nREVERSING OF THE LIST: ";
            l.reverse();
            cout<<"\nAFTER REVERSING LIST IS: ";
            l.disp_list();
            break;
        }
    case 9:
        {   
		    
            cout<<"\nCONCATENATION OF LISTS: ";
            l1.concat(l);
            break;
        }
    case 10:
        {
            int item;
            cout<<"\nENTER ELEMENT YOU WANT TO SEARCH: ";
            cin>>item;
            cout<<"\nSEARCHING OF ELEMENT IN LIST: ";
            l.search(item);
        }
    case 11:
        {
           cout<<"\nTHE NUMBER OF NODES: ";
            l.count();
            break;
        }
    default:
        cout<<"\nWRONG CHOICE.";
        }

        cout<<"\nDO YOU WANT TO CONTINUE?: ";
        cin>>ch;
    }while(ch=='y'||ch=='Y');
        return 0;

}

