#include<iostream.h>
template<class T>
class dnode
{
  public:
  T info;
  dnode<T>*next;
  dnode<T>*previous;
  dnode(T x)
  {
  info=x;
   next=NULL;
   previous=NULL;
   }
   
 };
 template <class t>
 class dllist
 {
   public:
   dnode<t>* header;
   dnode<t>*trailer;
   dllist()
    {
    header=NULL;
	trailer=NULL;
    }
		int isempty()
	{
	if(header==NULL)
	return 1;
	else
	return 0;
	}
	dnode<t>* createnode(t x);
	void addtohead(t x);
	void addtotail(t x);
    void insertion(dnode<t>*temp,int position);
	t remove(int position);
	dnode<t>* search(t y);
	dllist  operator+(dllist<t>ob1);
	dllist reverse();
	void display();
	void clear();
};
    template <class t>
	dnode<t>* dllist<t>:: createnode(t x)
	{
	  dnode<t>*temp=new dnode<t>(x);
	  return temp;
	 }
	 template <class t>
	 void dllist<t>:: addtohead(t x)
	 {
	 dnode<t>*temp=new dnode<t>(x);
	 	if(header==NULL)
		 {
		   header=temp;
		   trailer=temp;
		  }
		  else
		  {
		    temp->next=header;
			header=temp;
		}
	 }
	 template <class t>
	 void dllist<t>:: addtotail(t x)
    {
     dnode<t>*temp=new dnode<t>(x);
	 if(header==NULL)
	 {
	   trailer=temp;
	   header=temp;
	  }
	  
	  else
	  
	  {
	   	temp->previous=trailer;
	    trailer->next=temp;
		trailer=temp;
	  }

	
	}	   	    
     template <class t>
	 void dllist<t>::insertion(dnode<t>*temp,int position) 
	 {
	   
	   dnode<t>*temp1=header;

	      for(int i=1;i<position-1;i++)
		  {
		    temp1=temp1->next;	  
		  }
		  temp->next=temp1->next;
		  temp->previous=temp1;
		  temp1->next=temp;
		  temp->next->previous=temp;
	}
	template <class t>
	t dllist<t>:: remove(int position)
	{
	  t x;
	  	dnode<t>*temp;
	  	if(header==trailer && header!=NULL)
	  	{
	  	x=header->info;
		temp=header;
		delete temp;
		header=NULL;
		trailer=NULL;
		}
		
	   
	   else
	    
		{
	   
		 if(position==1)
		{
		   temp=header;
		   header=header->next;
		   header->previous=NULL; 
		   x=temp->info;
		   delete temp;
		   
		  }
		  else if(position==-1)
		  {
		   temp=trailer;
		   temp->previous->next=NULL;
		   x=temp->info;
		   trailer=trailer->previous;
		   delete temp;
		   } 
		 else 
		 {
		 	
		  for(int i=1;i<position;i++)
	   		{
	     	temp=temp->next;
			}
			x=temp->info;
	    	temp->previous->next=temp->next;
			temp->next->previous=temp->previous;	
			delete temp;
		}	 
	
		}
		return x;
	}
	template <class t>
    dnode<t>* dllist<t>:: search(t y)
	{
	 dnode<t>* temp=header->next;
	 if(y==header->info)
	 {
	  return header;
	  }
	  else if(y==trailer->info)
	  {
	   return trailer;
	  }
	  else
	  { 
	 while(temp!=NULL)
	 {
	     if(y==temp->info)
		 break;
		 else
		 temp=temp->next;
	 }
	 return temp;
	 }	  
	}
  
      template <class t>
	  dllist<t> dllist<t>::  operator+(dllist<t>ob1)
	 {
	 dllist<t>ob3;
     dnode<t>*temp1=header;
	 dnode<t>*temp2=ob1.header;
	 while(temp1!=NULL)
	 {
	   ob3.addtotail(temp1->info);
	   temp1=temp1->next;
	  }
	  while(temp2!=NULL)
	  
	  {
	   	      	   
	    ob3.addtotail(temp2->info);
	   temp2=temp2->next;	
	   }
	   return ob3;
	   }
	   template <class t>
	   dllist<t> dllist<t>:: reverse()
	   {
	     dllist ob3;
		 dnode<t>*temp=header;
		 while(temp!=NULL)
		 {
		 ob3.addtohead(temp->info);
		 temp=temp->next;
		 }
		 return ob3;
		} 
	   
	template <class t>
	void dllist<t>::display()
	{    
	dnode<t>*temp=header;
	while(temp!=NULL)
	{
		cout<<temp->info<<"   ";
		temp=temp->next;
	}
	}
	    template <class t>
		void dllist<t>::clear()
		{
		dnode<t>*temp=header;
		while(temp!=NULL)
		{
		  delete temp;
		  temp=temp->next;
		 }
		 cout<<"\n List cleared!!  ";
		 }
	   
	   int main()
	   {   	    
		 
	       char c='y'; 
		   dllist<int>l1;
		   dllist<int>l2;
		   dllist<int>l3;
		   dllist<int>l4;
		   dnode<int>*temp=NULL;
		   int element1;
           int x;
		   int ch;
		   int y; 
		   int a=1;
		   int count1=0;
		   int count2=0;
		   int pos;
		   cout<<"\n Enter elements for doubly linked list  1! ";
		   while(c=='y')
		   {
		   cout<<"\n Enter element: ";
		   cin>>x;
		   count1++;
		   l1.addtotail(x);
		   cout<<"\n Do you want to add more elements (y/n)? ";
		   cin>>c;
		   }
		   c='y';
		   cout<<"\n First  linked list consists  of:  ";
		   cout<<"\n";
		   l1.display();
		   
		   cout<<"\n Enter elements for doubly linked list 2!  ";
		   while(c=='y')
		   {
		   cout<<"\n Enter element: ";
		   cin>>x;
		   l2.addtotail(x);
		   count2++;
		   cout<<"\nDo you want to add more elements (y/n)? ";
		   cin>>c;
		   }
		   c='y';
		   cout<<"\n Second  linked list consists  of:  ";
		   cout<<"\n";
		   l2.display();
		   
		  
		   while(c=='y')
		   {
		   cout<<"\n*********MAIN MENU**********";
		   cout<<"\n 1.Insert element at starting! ";  
		   cout<<"\n 2.Insert element at i th position! ";
		   cout<<"\n 3.Insert at end positon! ";
		   cout<<"\n 4.Remove element from starting! ";
		   cout<<"\n 5.Remove element from ith position! ";
		   cout<<"\n 6.Remove from end position! ";
		   cout<<"\n 7.Search for element! ";
		   cout<<"\n 8.Concatenate! ";
		   cout<<"\n 9.To reverse a Doubly Linked List! "; 
		   cout<<"\nEnter your choice: ";
		   cin>>ch;
		   switch(ch)
		   {
		   case 1:
		   {
		   	cout<<"\n Enter element:  ";
			cin>>x;
			cout<<"\n Where to insert doubley linked list 1 or doubley linked list 2  (1/2)?  ";
			cin>>y;
			if(y==1)
			{
		    	l1.addtohead(x);
				count1++;
				cout<<"\n Present list 1";
				cout<<"\n";
				l1.display();
				break;
			}
			if(y==2)
			{
				l2.addtohead(x);
				count2++;
				cout<<"\n Present list 2";
				cout<<"\n";
				l2.display();
				break;
			}
			}
			
			case 2:
			{
		   	cout<<"\n Enter element";
			cin>>x;
			cout<<"\n Where to insert doubley linked list 1 or doubley linked list 2  (1/2)?  ";
			cin>>y;
			if(y==1)
				{
				cout<<"\n Enter the position for inserting the element  (2- "<<count1<<")";
				cin>>pos;
				if(pos>count1)
				{
				cout<<"\n No such position exists ";
				break ;
				}
			else
				{
				temp=new dnode<int>(x);
				l1.insertion(temp,pos);
				cout<<"\n Present list";
				count1++;
				cout<<"\n";
				l1.display();
				break;
				}
				}
				if(y==2)
				{
				cout<<"\n Enter the position for inserting the element  (2- "<<count2<<")";
				cin>>pos;
			    if(pos>count2)
				{
				cout<<"\n No such position exists ";
				break ;
				}
			else
			{
			temp=new dnode<int>(x);
			l2.insertion(temp,pos);
			cout<<"\n Present list";
			count2++;
			cout<<"\n";
			l2.display();
			break;
			}
			}
			}
			case 3:
			{
			  cout<<"\n Enter  the element for appending at the last position  ";
			  cin>>x;
			  
		   	cout<<"\n From where to remove the element  from  doubely linked  list 1 or doubely linked  list 2  (1/2)?  ";
			cin>>y;
			if(y==1)
			{
				l1.addtotail(x);
				cout<<"\n Present doubley linked list 1: ";
				l1.display();
			}
			if(y==2)
				{
				l2.addtotail(x);
				cout<<"\n Present doubley linked list 2: ";
				l2.display();
			}	
			break;
			}   
			case 4:
		   {
		   	cout<<"\n From where to remove the element  from  doubely linked  list 1 or doubely linked  list 2  (1/2)?  ";
			cin>>y;
			if(y==1)
				{
		         int element=l1.remove(1);
				 count1--;
				 cout<<"\n Popped element  "<<element ;
				 break;
				 
				}
			if(y==2)
			
				{
			
			     int element=l2.remove(1);
				 count2--;
				 cout<<"\n Popped element  "<<element ;
				 break;
				 
				}
				}
			case 5:
			{
			cout<<"\n From where to remove the element  list 1 or list 2(1/2)?";
			cin>>y;
			if(y==1)
				{
				cout<<"\n Enter the position from where to remove  the element  (2- "<<count1--<<")";
				cin>>pos;
			if(pos>count1)
				{
				cout<<"\n No such position exists! ";
				break ;
				}
			else
			{
				temp=new dnode<int>(x);
			  	 element1= l1.remove(pos);
				cout<<"\n Popped element "<<element1;
				cout<<"\n";
				break;
			}
			}
			if(y==2)
			     {
				 cout<<"\n Enter the position from where to remove the element (2-"<<count2--<<")  ";
				 cin>>pos;
				 if(pos>count2)
 	 	 	 	  {
				 	cout<<"\n No such position exists ";
					break ;
				}
			else
			{
				temp=new dnode<int>(x);
			  	element1= l2.remove(pos);
				cout<<"\n Popped element "<<element1;
				cout<<"\n";	   	   	      
				break;
			}
			   
			}
			}
				case 6:
		   {
		   	cout<<"\n From where to remove the element  from  doubely linked  list 1 or doubely linked  list 2  (1/2)?  ";
			cin>>y;
			if(y==1)
				{
		         int element=l1.remove(-1);
				 count1--;
				 cout<<"\n Popped element  "<<element ;
				 break;
				 
				}
			if(y==2)
			
				{
			
			     int element=l2.remove(-1);
				 count2--;
				 cout<<"\n Popped element  "<<element ;
				 break;
				 
				}
				}
			case 7:
			{
			cout<<"\n";
			cout<<"\n From where to remove the element  from  doubely linked  list 1 or doubely linked  list 2  (1/2)?   ";
			cin>>y;
			if(y==1)
			{
			
		    	int n=l1.isempty();
				if(n==1)
				{
				cout<<"\nDoubley linked list 1 is  empty!";
				break;
				}
				
			else
			{
				cout<<"\n Enter element to be searched :  ";
				cin>>element1;
				temp=l1.search(element1);
				if(temp!=NULL)
				cout<<"\n   "<<temp->info;
				else
				cout<<"\n Element not found in list 1 ";
				
				
				break;
			}
			}
		    if(y==2)
			{
			
		    	int n=l2.isempty();
				if(n==1)
				{
			    cout<<"\nDoubley linked list 2 is  empty";
				break;
				}
			else
			{
				cout<<"\n Enter element to be searched   ";
				cin>>element1;
				temp=l2.search(element1);
				if(temp!=NULL)
				cout<<"\n  "<<temp->info;
				else
				cout<<"\n Element not found in list 2  ";
				break;
				
				
			}
			}
			}	   
			case 8:
			   {
			    l3=l1+l2;
				cout<<"\n";
			    cout<<"\n Concatenated list ";
				cout<<"\n";
				l3.display();
				break;
			   }
			 case 9:
			   {
		   		cout<<"\nWhich    doubely linked  list 1 or doubely linked  list 2 to reverse   (1/2)  ";
				cin>>y;
				if(y==1)
				{
				if(!(l1.isempty()))
				{
				 cout<<"\n ";
				 cout<<"\n Original list ";
				 l1.display();
		         l4=l1.reverse();
				 cout<<"\n Reversed list  ";
				 l4.display();
				 break;
				 }
				 
				 else
				 {
				 cout<<"\n EMPTY LIST ";
				 break;
				 }
				 
				}
			if(y==2)
			
				{
				if(!(l2.isempty()))
				{
			
			      cout<<"\n ";
				 cout<<"\n Original list ";
				 l2.display();
		         l4=l2.reverse();
				 cout<<"\n Reversed list  ";
				 l4.display();
				 break;
				 }
				 else
				 {
				 cout<<"\n EMPTY LIST ";
				 break;
				 }
				}
				}
	             	 	    
			   	
	          }
			
			
			cout<<"\n Do you wish to continue?(y/n)   ";
			cin>>c;
			}
			if(!(l1.isempty()))
			{
			  l1.clear();
			}
			if(!(l2.isempty()))
			{
			  l2.clear();
			}
			if(!(l3.isempty()))
			{
			  l3.clear();
			}
		   	 if(!(l4.isempty()))
			{
			  l4.clear();
			}  
			return 0;
			}
	   
	    

