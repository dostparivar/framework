#include<iostream.h>
#include<math.h>
#include<conio.h>
class ISBN
{
	private:
	long n;
	public:
	void input();
	long check(long x);
	void compute();
};
void ISBN::input()
{
	cout<<"This program generates all possible ISBN numbers from a nine digit"<<
	"\nnumber entered by the user. Any ISBN number is a 10 digit number such that"<<
	"\nthe sum of the first digit multiplied by 9, the second digit multiplied by"<<
	"\n 8 upto the first digit is divisible by 11.";
	cout<<"\n\nPlease enter the number(if the first digit is a zero, it is not entered). ";
	cin>>n;
	cout<<"\n\nThe possible ISBN numbers are:\n";
}
long ISBN::check(long x)
{
	long i=1,sum=0;
	while(i<=9)
	{
		sum+=x%10*i++;
		x/=10;
	}
	if(sum%11==0)
	return 1;
	return 0;
}
void ISBN::compute()
{
	long i=0,j,k,c,count=0,temp=n,a[9]={0};
	while(i<9)
	{
		a[i]=(temp/((long)pow(10,8-i)))%10;
		i++;
	}
	for(i=1;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			temp=0,c=0;
			for(k=0;k<10;k++)
			{
				if(k==i)
				temp+=j*pow(10,9-k);
				else
				temp+=a[c++]*pow(10,9-k);
			}
			if(check(temp))
			count++,cout<<temp<<"\n";
		}
	}
	cout<<"\n\nThere are "<<count<<" such numbers.";
	cout<<"\n\n\nPROGRAM TERMINATED.";
}
void main()
{
	ISBN k;
	k.input();
	k.compute();
	getch();
}