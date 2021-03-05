#include<iostream>
using namespace std;

template <class S>
class searching
{
 S data[20];
 S ele;
 int n;

  public:
          
		  searching()
		  {
		  ele='null';
		  n=-1;
		  }
		  
		  int binarysearch();
		  int linearsearch();
		  void input();
		  


};
template<class S>
void searching<S>::input()
		  {
		   cout<<"Enter size of array :";
		   cin>>n;
		   
		   cout<<"Enter array elements: ";
   
   		for(int k=0; k < n; k++)
    		cin>>data[k];
			
			cout<<"Enter the Element you want  to search for :";
			cin>>ele;
			
		   }
template<class S>		   
int searching<S>::binarysearch()
{
    int beg, last, mid;
   beg = 0;
   last = n - 1;
   while(beg <= last)
     { 
	    mid = (beg + last)/2;
		
		if(ele == data[mid])
			return mid;
			
		else if(ele < data[mid])
			last = mid - 1;
		else
			beg = mid + 1;
	 }
	 
	 return -1;	     	  
}	 	    
	
template<class S>	
int searching<S>::linearsearch()
{
    int i;
	for(i = 0; i < n; i++)
	{
	  if(data[i] == ele)
	  return i; 
	}	 
   return -1;
}	 	    
 	 	    
			   
  	  	  
  void menu()
  {
  cout<<"\n___________________________________________________________________________";
        cout<<"\n\n\t\t1.Binary Search\t\t 2.Linear Search\n\n\t\t 3.Exit";
  }	   
  

int main()
{
   searching<int> s;
   
   char choice='n';
   int ch,pos;
    s.input();
	
   while (choice=='n')
   {
	
  
                menu();
                cout<<"\nEnter the choice\n";
                cin>>ch;
				
                switch(ch)
				{
                
                        case 1:
							pos=s.binarysearch();
							if(pos>0)
							 cout<<"The element is found at index no. :"<<pos;
							else
							 cout<<"element not found"; 
	                    	break;
	                    case 2:
							pos=s.linearsearch();
							if(pos>0)
							 cout<<"The element is found at index no. :"<<pos;
							else
							 cout<<"element not found"; 
	                   	 	break;
	                    case 3:
							cout<<"are you sure you want to exit<y/n> :";
							cin>>choice;
							break;
	                  default: cout<<"Wrong choice";
				}	 	 
	}
	              	 
         return 0;
  }

