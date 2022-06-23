#include<iostream.h>
#include<conio.h>
#include<math.h>
class NumberMultiple
{
	public:
	long divisibility(long n);
	void display();
};
void NumberMultiple::display()
{
	long i,j=0;
	cout<<"This program is designed to generate all nine digit numbers divisible"<<
	"\nby nine. when the ninth digit is removed it is divisible by eight, "<<
	"\nwhen tha all digits form the eigth digit is removed it is divisible by"<<
	"\nseven and so on uptill the removal of all digits from the second digit.";
	cout<<"\n\nPlease press enter to begin ";
	getch();
	cout<<"\n\n";
	cout<<"The numbers is:\n";
	for(i=381654729;i<999999999;)
	{
		j+=divisibility(i);
		i+=9;
	}
   cout<<"There are "<<j<<" such numbers present.\n";
	cout<<"\n\nPROGRAM TERMINATED.";
}
long NumberMultiple::divisibility(long n)
{
	long i,j,a[9],sum,f=1;
	if(n%9!=0)
	{
		f=0;
		goto end;
	}
	else
	{
		for(i=0;i<9;i++)
		a[i]=(long)(n/pow(10,8-i))%10;
		for(i=0;i<9;i++)
		{
			for(j=0;j<9;j++)
			{
				if(i!=j&&a[i]==a[j])
				{
					f=0;
					goto end;
				}
			}
		}
		for(i=8;i>=1;i--)
		{
			sum=0;
			for(j=0;j<=i-1;j++)
			sum=sum*10+a[j];
			if(sum%i!=0)
			f=0;
			if(f==0)
			goto end;
		}
		if(f==1)
		{
			cout<<n<<":\n";
			cout<<n<<"%9=0\n";
			for(i=8;i>=1;i--)
			{
				sum=0;
				for(j=0;j<=i-1;j++)
				sum=sum*10+a[j];
				cout<<sum<<"%"<<i<<"="<<(sum%i)<<"\n";
			}
			cout<<"\n";
		}
	}
	end:
	return f;
}
void main()
{
	NumberMultiple k;
	k.display();
	getch();
}
