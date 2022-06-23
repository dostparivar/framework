#include<iostream.h>
#include<conio.h>
struct node
{
	node* prev;
	node* next;
	int x;
};
class LinkList
{
	private:
	int n;
	node *first,*last,*current;
	public:
	LinkList();
	void create();
	int sum();
	void display();
};
LinkList::LinkList()
{
	n=0;
	first=NULL,last=NULL,current=NULL;
}
void LinkList::create()
{
	int i;
	cout<<"This program implements a double link list and calculates the sum of elements.\n";
	cout<<"\nPlease enter the number of elements.";
	cin>>n;
	first=new node;
	cout<<"\nPlease enter the first element. ";
	cin>>first->x;
	first->prev=NULL;
	last=first;
	for(i=1;i<n;i++)
	{
		current=new node;
		cout<<"Enter element "<<(i+1)<<". ";
		cin>>current->x;
		last->next=current;
		current->prev=last;
		last=current;
	}
	last->next=NULL;
}
int LinkList::sum()
{
	int s=0,i=0;
	current=first;
	for(i=0;current!=NULL;i++)
	{
		s+=current->x;
		current=current->next;
	}
	return s;
}
void LinkList::display()
{
	cout<<"The sum of elements of the link list is "<<sum()<<".\n";
	cout<<"\n\n\nPROGRAM TERMINATED.";
}
void main()
{
	LinkList k;
	k.create();
	k.display();
	getch();
}