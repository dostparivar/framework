#include<iostream.h>
#include<conio.h>
class Merge
{
	private:
	int a[50],b[50],c[100],l1,l2,l3;
	public:
	Merge();
	void input();
	int min1();
	int min2();
	void merging();
	void display();
};
Merge::Merge()
{
	clrscr();
	int i;l1=0,l2=0,l3=0;
	for(i=0;i<50;i++)
	a[i]=0,b[i]=0,c[i]=0,c[i+50]=0;
}
void Merge::input()
{
	int i;
	cout<<"This program is designed to merge two arrays without sorting them.\n";
	cout<<"\nPlease enter the number of elements in the first array. ";
	cin>>l1;
	cout<<"Please enter the number of elements in the second array. ";
	cin>>l2;
	cout<<"\nPlease enter the elements of the first array.\n";
	for(i=0;i<l1;i++)
	{
		cout<<"Element "<<(i+1)<<": ";
		cin>>a[i];
	}
	cout<<"\nPlease enter the elements of the second array.\n";
	for(i=0;i<l2;i++)
	{
		cout<<"Element "<<(i+1)<<": ";
		cin>>b[i];
	}
	cout<<"\n\nThe two arrays of size "<<l1<<" and "<<l2<<" are merged into an array\n"<<
	"of length "<<l1+l2<<": \n";
}
int Merge::min1()
{
	int i,j,min=a[0];
	for(i=0;i<l1;i++)
	if(min>a[i])
	min=a[i];
	for(i=0;i<l1;i++)
	{
		if(a[i]==min)
		{
			for(j=i;j<l1;j++)
			a[j]=a[j+1];
			break;
		}
	}
	l1--;
	return min;
}
int Merge::min2()
{
	int i,j,min=b[0];
	for(i=0;i<l2;i++)
	if(min>b[i])
	min=b[i];
	for(i=0;i<l2;i++)
	{
		if(b[i]==min)
		{
			for(j=i;j<l2;j++)
			b[j]=b[j+1];
			break;
		}
	}
   l2--;
	return min;
}
void Merge::merging()
{
	int t1=min1(),t2=min2();
	while(l1>-1||l2>-1)
	{
		if(t1<=t2&&l1>=0&&l2>=0)
		{
			c[l3++]=t1;
			t1=min1();
		}
		else if(l1>=0&&l2>=0)
		{
			c[l3++]=t2;
			t2=min2();
		}
		if(l1<0)
		{
			c[l3++]=t2;
			t2=min2();
		}
		if(l2<0)
		{
			c[l3++]=t1;
			t1=min1();
		}
	}
	l3--;
}
void Merge::display()
{
	int i;
	for(i=0;i<l3;i++)
	cout<<c[i]<<" ";
	cout<<"\n\n\nPROGRAM TERMINATED.";
}
void main()
{
	Merge k;
	k.input();
	k.merging();
	k.display();
	getch();
}