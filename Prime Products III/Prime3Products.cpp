#include<iostream.h>
#include<conio.h>
class PrimeProducts
{
	private:
	long n,ll,ul,choice;
	public:
	long factor(long x);
	void input();
	void display();
};
long PrimeProducts::factor(long x)
{
	long i;
	for(i=2;i<x;i++)
	if(x%i==0)
	return i;
	return 1;
}
void PrimeProducts::input()
{
	cout<<"This Program is designed to print as many triplets of consequtive\n"<<
	"numbers which are products of three prime factors as input by the user.\n";
	cout<<"\n1:Display all such triplets within a limit.";
	cout<<"\n2:Display as many triplets as asked by the user from 1 onwards.";
	cout<<"\n\nPlease enter your choice. ";
	cin>>choice;
	if(choice==1)
	{
		cout<<"\nPlease enter the lower limit. ";
		cin>>ll;
		cout<<"Please enter the upper limit. ";
		cin>>ul;
		n=100000000;
		cout<<"\nThe triplets are:\n\n";
	}
	else if(choice==2)
	{
		cout<<"\nPlease enter the number of such triplets to be displayed. ";
		cin>>n;
		ll=1,ul=100000000;
		cout<<"\nThe triplets are:\n\n";
	}
	else
	cout<<"\nInvalid Choice.";
}
void PrimeProducts::display()
{
	long i,j,c=0,f;
	if(choice!=1&&choice!=2)
	goto end;
	for(i=ll;i<=ul-2&&c<n;i++)
	{
		f=1;
		for(j=i;j<=i+2;j++)
		if(factor(j)==1||factor(j/factor(j))==1||factor((j/factor(j))/factor(j/factor(j)))!=1)
		f=0;
		if(f==1)
		{
			c++;
			cout<<i<<", "<<(i+1)<<", "<<(i+2)<<".          "<<"("<<i<<"="<<
			factor(i)<<"X"<<factor(i/factor(i))<<"X"<<(i/factor(i))/factor(i/factor(i))<<
			", "<<(i+1)<<"="<<factor(i+1)<<"X"<<factor((i+1)/factor(i+1))<<"X"<<
			((i+1)/factor(i+1))/(factor((i+1)/factor(i+1)))<<", "<<(i+2)<<
			"="<<factor(i+2)<<"X"<<factor((i+2)/factor(i+2))<<"X"<<
			((i+2)/factor(i+2))/(factor((i+2)/factor(i+2)))<<".)\n";
		}
	}
	if(choice==1&&c==0)
	cout<<"\nThere are no such triplets between "<<ll<<" and "<<ul<<".";
	if(choice==1&&c==1)
	cout<<"\nThere is only one such triplet between "<<ll<<" and "<<ul<<".";
	if(choice==1&&c>1)
	cout<<"\nThere are "<<c<<" such triplet between "<<ll<<" and "<<ul<<".";
   end:
	cout<<"\n\nPROGRAM TERMINATED.";
}
void main()
{
	PrimeProducts k;
	k.input();
	k.display();
	getch();
}