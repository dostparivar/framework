#include<iostream.h>
#include<conio.h>
class Factorial
{
	private:
	long n,l,a[1000];
	public:
	void input();
	void compute();
	void display();
};
void Factorial::input()
{
	clrscr();
	cout<<"This program is designed to display all the digits of the factorial"<<
	"\nof a number input by the user.\n";
	cout<<"\nPlease enter the number whose factorial is to be printed. ";
	cin>>n;
}
void Factorial::compute()
{
	long i,j,x,temp;
	a[999]=1;
	for(i=0;i<999;i++)
	a[i]=0;
	for(i=1;i<=n;i++)
	{
		x=0;
		for(j=999;j>=0;j--)
		{
			temp=a[j];
			a[j]=(temp*i+x)%10;
			x=(temp*i+x)/10;
		}
	}
	for(i=0;i<=999;i++)
	if(a[i]!=0)
	{
		l=i;
		break;
	}
}
void Factorial::display()
{
	long i;
	cout<<"\nThe factorial of "<<n<<" is:\n";
	for(i=l;i<=999;i++)
	cout<<a[i];
	cout<<"\n\nPROGRAM TERMINATED.";
}
void main()
{
	Factorial k;
	k.input();
	k.compute();
	k.display();
	getch();
}