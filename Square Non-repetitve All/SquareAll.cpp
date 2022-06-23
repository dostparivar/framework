#include<iostream.h>
#include<conio.h>
class SquareAll
{
	public:
	void input();
	void compute();
	long check(long x);
	long len(long x);
};
void SquareAll::input()
{
	cout<<"This Program generates all numbers which along with their squares have"<<
	"\nall the digits in them.";
	cout<<"\n\nPlease press enter to begin. ";
	getch();
	cout<<"\nThe Numbers are:\n";
}
long SquareAll::len(long x)
{
	long c=0;
	while(x!=0)
	{
		c++;
		x/=10;
	}
	return c;
}
long SquareAll::check(long x)
{
	long a[10]={0},i,j,temp,c=0;
	if((len(x)+len(x*x))!=9)
	return 0;
	temp=x;
	while(temp!=0)
	{
		a[c++]=temp%10;
		temp/=10;
	}
	temp=x*x;
	while(temp!=0)
	{
		a[c++]=temp%10;
		temp/=10;
	}
	for(i=0;i<c;i++)
	for(j=0;j<c;j++)
	if((a[i]==a[j]&&i!=j)||a[j]==0)
	return 0;
	return 1;
}
void SquareAll::compute()
{
	long i,c=0;
	for(i=0;i<10000;i++)
	if(check(i))
	cout<<"x="<<i<<", x*x="<<i*i<<".\n",c++;
	cout<<"\nThere are "<<c<<" such numbers.";
	cout<<"\n\nPROGRAM TERMINATED.";
}
void main()
{
	SquareAll k;
	k.input();
	k.compute();
	getch();
}