#include<iostream.h>
#include<conio.h>
class BinarySearch
{
	private:
	int a[100],n,l;
	public:
	BinarySearch();
	void input();
	void sort();
	int search(int,int);
	void display();
};
BinarySearch::BinarySearch()
{
	int i;
	for(i=0;i<100;i++)
	a[i]=0;
	n=0;
}
void BinarySearch::input()
{
	clrscr();
	int i;
	cout<<"This program is designed to sort and search an array using recurscive binary\n"<<
	"search.";
	cout<<"\n\nPlease enter the number of elements in the array. ";
	cin>>l;
	for(i=0;i<l;i++)
	{
		cout<<"Enter element "<<(i+1)<<". ";
		cin>>a[i];
	}
	cout<<"\nPlease enter the element to be searched. ";
	cin>>n;
}
void BinarySearch::sort()
{
	int i,j,t;
	for(i=0;i<l;i++)
	for(j=0;j<l-1;j++)
	{
		if(a[j]>a[j+1])
		{
			t=a[j+1];
			a[j+1]=a[j];
			a[j]=t;
		}
	}
}
int BinarySearch::search(int ll,int ul)
{
	int mid=(ll+ul)/2;
	if(n>a[mid]&&ll<=ul)
	{
		ll=mid+1;
		return search(ll,ul);
	}
	if(n<a[mid]&&ll<=ul)
	{
		ul=mid-1;
		return search(ll,ul);
	}
	if(a[mid]==n)
	return mid;
	if(ll>ul)
	return -1;
}
void BinarySearch::display()
{
	int t=search(0,l);
	if(t==-1)
	cout<<"\n\nThe number "<<n<<" does not exist in the array.\n";
	else
	cout<<"\n\nthe number "<<n<<" is persent at position "<<t+1<<" in the array.\n";
	cout<<"\n\nPROGRAM TERMINATED.";
}
void main()
{
	BinarySearch k;
	k.input();
	k.sort();
	k.display();
	getch();
}