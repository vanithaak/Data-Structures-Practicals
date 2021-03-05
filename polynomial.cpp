#include<iostream>
using namespace std;

template<class T>
class polyn
{
 public:
   T info;
   T pow;
   polyn *next;
   polyn(T x,T y,polyn *n=0)
   { 
     
     info=x;
	 pow=y;
	 next=n;
   }   
};

template<class T>
class polyl
{
  polyn<T>*head;
  public:
    polyl()
	{ 
	  head =0;
	}
	void addtotail(T x,T y);
	int isempty();
	void display();
	polyl<T>operator+ (polyl ob1);
};


template<class T>
int polyl<T>::isempty()
{
 if(head==0)
    return 1;
 else 
    return 0;
}

template<class T>
void polyl<T>::addtotail(T x,T y)
{
  polyn<T>*curr;
  polyn<T>*temp;
  temp=new polyn<T>(x,y);
  
  if(isempty())
  {
    polyn<T> *tail=temp;
    head=tail;
  }
  else 
  {
    curr=head;
	while(curr->next!=0)
	 {
	   curr=curr->next;
	 }
	 curr->next=temp;
  }
}

template<class T>
void polyl<T>::display()
{
  if(!isempty())
  {
   polyn<T>*temp;
   cout<<"\nTHE POLYNOMIAL IS: ";
   for(temp=head;temp!=NULL;temp=temp->next)
   {
     cout<<"("<<temp->info<<"x^"<<temp->pow<<"+";
	 cout<<"\n";
   }
  }
}

template<class T>
polyl<T> polyl<T> :: operator+(polyl<T> ob1)
{
   polyl<T>ob3;
   
   polyn<T> *temp1=(*this).head;
   polyn<T> *temp2=ob1.head;
   while(temp1!=0 && temp2!=0)
   {
     if(temp1->pow==temp2->pow)
	 {
	   ob3.addtotail((temp1->info)+(temp2->info),temp1->pow);
	   temp1=temp1->next;
	   temp2=temp2->next;
	 }
	 else if((temp2->pow)>(temp1->pow))
	 {
	   ob3.addtotail(temp2->info,temp2->pow);
	   temp2=temp2->next;
	 } 
	 else
	 {
	   ob3.addtotail(temp1->info,temp1->pow);
	   temp1=temp1->next;
	 }
   }
   while(temp1!=0)
   {
     ob3.addtotail(temp1->info,temp1->pow);
	 temp1=temp1->next;
   }
   while(temp2!=0)
   {
     ob3.addtotail(temp2->info,temp2->pow);
	 temp2=temp2->next;
   }
  return ob3;
}

int main()
{
  polyl<int>p1,p2,p3;
  int x,y;
  char ch1,ch2;
  cout<<"\nENTER THE 1st POLYNOMIAL: ";
  do
  {
   cout<<"\nENTER COEFFICIENTS: ";
   cin>>x;
   cout<<"\nENTER THE POWER: ";
   cin>>y;
   p1.addtotail(x,y);
   cout<<"\n DO YOU WANT TO ENTER MORE NODES: ";
   cin>>ch1;
  }while(ch1=='y'||ch1=='Y');
  
   p1.display();
   
   cout<<"\nENTER 2nd POLYNOMIAL : ";
   do 
   {
     cout<<"\nENTER COEFFICIENTS: ";
     cin>>x;
     cout<<"\nENTER THE POWER: ";
     cin>>y;
     p2.addtotail(x,y);
     cout<<"\n DO YOU WANT TO ENTER MORE NODES: ";
     cin>>ch2;
   }while(ch2=='y'||ch2=='Y');
   p2.display();
   p3=p1+p2;
   cout<<"\nTHE 3RD POLYNOMIAL IS: ";
   p3.display();
}



