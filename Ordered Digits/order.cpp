#include<iostream.h>
#include<conio.h>
class OrderedDigits
{
	private:
	long n,a[9];
	public:
	OrderedDigits();
	void input();
	void display();
};
OrderedDigits::OrderedDigits()
{
	n=0;
	for(long i=0;i<9;i++)
	a[i]=0;
}
void OrderedDigits::input()
{
	clrscr();
	cout<<"This Program is designed to display all possible ways in which\n"<<
	"the digits 1 to 9 can be used in that order to generate a specific number"<<
	"\nwith only  + or - signs or linked up digits.\n";
	cout<<"For example- n=36\n1-23+45-56+78-9=36.\n\n";
	cout<<"Please enter the number which is to be generated using the digits. ";
	cin>>n;
	cout<<"\nThe possible ways in which "<<n<<" can be represented by the digits 1 to 9 are:\n";
}
void OrderedDigits::display()
{
	long  i,temp,c=0,pos,s,sumt,count=0,ct,t;
	while(c<6561)
	{
		temp=c++,sumt=0;
		while(temp!=0)
		{
			a[sumt++]=temp%3;
			temp/=3;
		}
		s=0,pos=0;
		for(i=1;i<=9;)
		{
			if(i==1&&a[pos]!=0)
			s+=i++;
			else if(i==1&&a[pos]==0)
			{
				sumt=0;
				for(pos=0;pos<9;pos++)
				{
					sumt=sumt*10+i++;
					if(a[pos]!=0)
					break;
				}
				s+=sumt;
			}
			if(i>9||pos>7)
			break;
			if(a[pos]!=0)
			{
				if(a[pos+1]!=0&&pos!=7)
				{
					if(a[pos]==1)
					s+=i++;
					if(a[pos]==2)
					s-=i++;
					pos++;
				}
				else if(a[pos+1]==0)
				{
					sumt=0,t=a[pos];
					for(ct=0;pos<8;pos++,ct++)
					{
						if(a[pos]!=0&&ct!=0)
						break;
						sumt=sumt*10+i++;
					}
					if(t==1)
					s+=sumt;
					if(t==2)
					s-=sumt;
				}
			}
			if(i>9||pos>7)
			break;
		}
		if(s==n)
		{
			count++,pos=0;cout<<"\n";
			for(i=1;i<=9;)
			{
				if(i==1&&a[pos]!=0)
				cout<<i++;
				else if(i==1&&a[pos]==0)
				{
					sumt=0;
					for(pos=0;pos<9;pos++)
					{
						sumt=sumt*10+i++;
						if(a[pos]!=0)
						break;
					}
					cout<<sumt;
				}
				if(a[pos]!=0)
				{
					if(a[pos+1]!=0&&pos!=7)
					{
						if(a[pos]==1)
						cout<<"+";
						if(a[pos]==2)
						cout<<"-";
						cout<<i++;
						pos++;
					}
					else if(a[pos+1]==0)
					{
						sumt=0,t=a[pos];
						for(ct=0;pos<8;pos++,ct++)
						{
							if(a[pos]!=0&&ct!=0)
							break;
							sumt=sumt*10+i++;
						}
						if(t==1)
						cout<<"+";
						if(t==2)
						cout<<"-";
						cout<<sumt;
					}
				}
            if(i>9||pos>7)
				break;
			}
			cout<<"="<<n;
		}
	}
	cout<<"\n\n";
	if(count==0)
	cout<<"Sorry, there are no possible ways to represent "<<n<<" by the digits 1 to 9 in that order.";
	else if(count==1)
	cout<<"There is only one possible way to represent "<<n<<" by the digits 1 to 9 in that order.";
	else
	cout<<"There are "<<count<<" possible ways to represent "<<n<<" by the digits 1 to 9 in that order.";
	cout<<"\n\nPROGRAM TERMINATED.";
}
void main()
{
	OrderedDigits k;
	k.input();
	k.display();
	getch();
}