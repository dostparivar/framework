#include<iostream.h>
#include<conio.h>
class Date
{
	private:
	long d1,m1,y1,d2,m2,y2,n;
	public:
	void input();
	long compute();
	void display();
};
void Date::input()
{
	cout<<"This Program is designed to take a date as input and the number of"<<
	"\ndays to be added or subtracted and displays the resulting date.";
	cout<<"\n\nPlease enter the date. ";
	cin>>d1;
	cout<<"Please enter the month. ";
	cin>>m1;
	cout<<"Please enter the year. ";
	cin>>y1;
	cout<<"\nPlease enter the number to be added( -ve if it is to be subtracted). ";
	cin>>n;
}
long Date::compute()
{
	long month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	long i,j,temp=0;
	if((y1%4==0&&y1%100!=0)||y1%400==0)
	month[2]=29;
	if(m1<1||m1>12)
	return 0;
	if(d1<1||d1>month[m1])
	return 0;
	d2=d1,m2=m1,y2=y1;
	if(n<0)
	{
		n=-n;
		for(i=0;i<m1;i++)
		temp+=month[i];
		if(n>=temp+d1)
		{
			temp=n-temp-d1;
			y2--;
			if((y2%4==0&&y2%100!=0)||y2%400==0)
			j=366;
			else
			j=365;
			while(temp>=j)
			{
				temp-=j;
				y2--;
				if((y2%4==0&&y2%100!=0)||y2%400==0)
				j=366;
				else
				j=365;
			}
			if((y2%4==0&&y2%100!=0)||y2%400==0)
			month[2]=29;
			else
			month[2]=28;
			for(i=12;temp>=month[i];i--)
			temp-=month[i];
			m2=i;
			d2=month[m2]-temp;
		}
		else if(n<temp+d1)
		{
			temp=temp+d1-n;
			for(i=0;temp>=month[i];i++)
			temp=temp-month[i];
			d2=temp,m2=i;
		}
		n=-n;
	}
	else
	{
   	temp=0;
		for(i=m2+1;i<=12;i++)
		temp+=month[i];
		if(n>month[m2]-d1+temp)
		{
			temp=n-temp-month[m2]+d1,y2++;
			if((y2%4==0&&y2%100!=0)||y2%400==0)
			j=366;
			else
			j=365;
			while(temp>j)
			{
				temp-=j;
				y2++;
				if((y2%4==0&&y2%100!=0)||y2%400==0)
				j=366;
				else
				j=365;
			}
			if((y2%4==0&&y2%100!=0)||y2%400==0)
			month[2]=29;
			else
			month[2]=28;
			for(i=0;temp>=month[i];i++)
			temp-=month[i];
			m2=i;
			d2=temp;
		}
		else if(n<=month[m2]-d1+temp)
		{
			temp=temp+month[m2]-d1-n;
			for(i=12;temp>=month[i];i--)
			temp-=month[i];
			m2=i;
			d2=month[m2]-temp;
		}
	}
	return 1;
}
void Date::display()
{
	char m[12][20]={"January","February","March","April","May","June","July","August","September","October","November","December"};
	if(compute())
	{
		cout<<"\n\nYou had entered "<<m[m1-1]<<" "<<d1<<" "<<y1<<".";
		if(n>0)
		cout<<"\nAdding "<<n<<" day(s) to this we get "<<m[m2-1]<<" "<<d2<<" "<<y2<<".";
		else
		cout<<"\nSubtracting "<<-n<<" day(s) to this we get "<<m[m2-1]<<" "<<d2<<" "<<y2<<".";
	}
	else
	cout<<"\n\nThe Date enterd was incorrect.";
	cout<<"\n\n\nPROGRAM TERMINATED.";
}
void main()
{
	Date k;
	k.input();
	k.display();
	getch();
}