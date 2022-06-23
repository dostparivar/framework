#include<iostream.h>
#include<conio.h>
class DateDifference
{
	private:
	long d1,m1,y1,d2,m2,y2,n;
	public:
	DateDifference();
	long check(long x);
	void input();
	void compute();
	void display();
};
DateDifference::DateDifference()
{
	d1=0,m1=0,y1=0,d2=0,m2=0,y2=0,n=0;
}
long DateDifference::check(long x)
{
	long month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	if(x==1)
	{
		if((y1%4==0&&y1%100!=0)||y1%400==0)
		month[2]=29;
		if(m1<1||m1>12)
		return 0;
		if(d1<1||d1>month[m1])
		return 0;
	}
	else
	{
		if((y2%4==0&&y2%100!=0)||y2%400==0)
		month[2]=29;
		if(m2<1||m2>12)
		return 0;
		if(d2<1||d2>month[m1])
		return 0;
	}
	return 1;
}
void DateDifference::input()
{
	long temp;
	cout<<"This Program accepts two dates and displays the difference of days"<<
	"\nbetween them.\n";
	cout<<"\nPlease enter the first date. ";
	cin>>d1;
	cout<<"Please enter the first month. ";
	cin>>m1;
	cout<<"Please enter the first year. ";
	cin>>y1;
	cout<<"\nPlease enter the second date. ";
	cin>>d2;
	cout<<"Please enter the second month. ";
	cin>>m2;
	cout<<"Please enter the second year. ";
	cin>>y2;
	if(check(1)==0)
	cout<<"\n\nThe first date entered is not valid.\n";
	if(check(2)==0)
	cout<<"\n\nThe second date entered is not valid.\n";
	if((y2>y1)||(y2==y1&&m2>m1)||(y2==y1&&m2==m1&&d2>d1))
	{
		temp=y2,y2=y1,y1=temp;
		temp=m2,m2=m1,m1=temp;
		temp=d2,d2=d1,d1=temp;
	}
}
void DateDifference::compute()
{
	long month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	long i;
	if(!(check(1)&&check(2)))
	goto end;
	if(y2<y1)
	{
		if((y2%4==0&&y2%100!=0)||y2%400==0)
		month[2]=29;
		n+=month[m2]-d2;
		for(i=m2+1;i<=12;i++)
		n+=month[i];
		n+=(y1-y2-1)*365;
		for(i=y2+1;i<y1;i++)
		if((i%4==0&&i%100!=0)||i%400==0)
		n++;
		if((y1%4==0&&y1%100!=0)||y1%400==0)
		month[2]=29;
		else
		month[2]=28;
		for(i=0;i<m1;i++)
		n+=month[i];
		n+=d1;
	}
	else if(y2==y1&&m2<m1)
	{
		if((y2%4==0&&y2%100!=0)||y2%400==0)
		month[2]=29;
		n+=month[m2]-d2;
		for(i=m2+1;i<m1;i++)
		n+=month[i];
		n+=d1;
	}
	else
	n=d1-d2;
   end:
}
void DateDifference::display()
{
	char m[13][20]={"","January","February","March","April","May","June","July","August","September","October","November","December"};
	if(check(1)&&check(2))
	{
		cout<<"\n\nThe date "<<m[m1]<<" "<<d1<<" "<<y1<<" comes "<<n<<" day(s) "<<
		"after the date "<<m[m2]<<" "<<d2<<" "<<y2<<".";
	}
	cout<<"\n\n\nPROGRAM TERMINATED.";
}
void main()
{
	DateDifference k;
	k.input();
	k.compute();
	k.display();
	getch();
}