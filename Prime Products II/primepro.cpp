#include<iostream.h>
#include<conio.h>
class PrimeProducts
{
	private:
	long n;
	public:
	long factorcheck(long);
	long factor(long);
	void compute();
	void input();
};
void PrimeProducts::input()
{

	cout<<"This program prints sets of three cosecutive numbers which are\n"<<
	"each a product of two prime factors.\n";
	cout<<"\nPlease enter the number of such sets to be printed. ";
	cin>>n;
	cout<<"\nThe numbers are:\n";
}
void PrimeProducts::compute()
{
	long i,count,num=0;
	if(n>0)
	for(i=0;i<n;i++)
	{
		count=0;
		do
		{
			num++;
			if(factorcheck(num))
			count++;
			else
			count=0;
		}while(count<3);
		cout<<num-2<<", "<<num-1<<", "<<num<<".             ("<<factor(num-2)<<
		"X"<<(num-2)/factor(num-2)<<"="<<num-2<<", "<<factor(num-1)<<"X"<<
		(num-1)/factor(num-1)<<"="<<num-1<<", "<<factor(num)<<"X"<<
		(num)/factor(num)<<"="<<num<<".)\n";
	}
	else
	cout<<"\n\nInvalid Input.";
	cout<<"\n\nPROGRAM TERMINATED.";
}
long PrimeProducts::factor(long a)
{
	for(int i=2;i<=a;i++)
	{
		if(a%i==0)
		return (a/i);
	}
}
long PrimeProducts::factorcheck(long a)
{
	if(factor(a)!=1&&factor(factor(a))==1)
	return 1;
	return 0;
}
void main()
{
	PrimeProducts k;
	k.input();
	k.compute();
	getch();
}