#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<string.h>
class Roman
{
	private:
	long n,choice;
	char a[100];
	public:
	Roman();
	void input();
	long compute();
	long value(char xt[3]);
	void display();
};
Roman::Roman()
{
	n=0,choice=0;
	long i;
	for(i=0;i<100;i++)
	a[i]='\0';
}
void Roman::input()
{
	cout<<"This program is designed to convert a number to Roman or a Roman"<<
	"\nto number.";
	cout<<"\n\n1:Convert a Number to Roman.\n2.Convert a Roman to Number.\n";
	cout<<"\nPlease enter your choice. ";
	cin>>choice;
	if(choice==1)
	{
		cout<<"\nPlease enter the number to be converted. ";
		cin>>n;
	}
	else if(choice==2)
	{
		cout<<"\nPlease enter the Roman to be converted. ";
		cin>>a;
	}
	else
	cout<<"\n\nInvalid choice. ";
}
long Roman::value(char xt[3])
{
	char xc[13][3]={"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
	long x[13]={1,4,5,9,10,40,50,90,100,400,500,900,1000};
	for(int i=0;i<=12;i++)
	{
		if(strcmp(xt,xc[i])==0)
		return x[i];
	}
	return 0;
}
long Roman::compute()
{
	long i,l,temp;
	char xc[13][3]={"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"},t[3]={'\0'};
	long x[13]={1,4,5,9,10,40,50,90,100,400,500,900,1000};
	if(choice==1)
	{
		temp=n,i=12;
		while(i>=0)
		{
			while(temp>=x[i])
			{
				temp-=x[i];
				strcat(a,xc[i]);
			}
			i--;
		}
		return 1;
	}
	if(choice==2)
	{
		l=strlen(a);
		for(i=0;i<l-3;i++)
		{
			if(a[i]==a[i+1]&&a[i]==a[i+2]&&a[i]==a[i+3])
			return 0;
		}
		for(i=0;i<l;i++)
		{
			if(a[i]!='I'&&a[i]!='V'&&a[i]!='X'&&a[i]!='L'&&a[i]!='C'&&a[i]!='D'&&a[i]!='M')
			return 0;
		}
		for(i=0;i<l;i++)
		{
			t[0]=a[i],t[1]=a[i+1],t[2]='\0';
			if(value(t)!=0)
			n+=value(t),i++;
			else
			{
				t[0]=a[i],t[1]='\0';
				n+=value(t);
			}
		}
		return 1;
	}
}
void Roman::display()
{
	if(choice==1&&n>0&&n<4000)
	{
		compute();
		cout<<"\nThe Roman Equivalent of "<<n<<" is "<<a<<".";
	}
	else if(choice==1)
	cout<<"\nRoman Numbers do not exist below 1 or above 3999.";
	else if(choice==2&&compute())
	cout<<"\nThe Integral equivalent of "<<a<<" is "<<n;
	else if(choice==2)
	cout<<"\nThe Roman Number entered is not valid. ";
	cout<<"\n\n\nPROGRAM TERMINATED.";
}
void main()
{
	Roman k;
	k.input();
	k.display();
	getch();
}