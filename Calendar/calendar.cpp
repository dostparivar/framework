#include<iostream.h>
#include<conio.h>
class Calendar
{
	private:
	long m,y,a[5][7];
	public:
	Calendar();
	void input();
	void compute();
	void display();
};
Calendar::Calendar()
{
	long i,j;
	m=0,y=0;
	for(i=0;i<5;i++)
	for(j=0;j<7;j++)
	a[i][j]=0;
}
void Calendar::input()
{
	clrscr();
	cout<<"We know that January 1,2005 was a Saturday. This program\n"<<
	"prints a calendar of the month and year entered by the user.\n";
	cout<<"\nPlease enter the number of the month. ";
	cin>>m;
	cout<<"Please enter the year. ";
	cin>>y;
}
void Calendar::compute()
{
	long i,j,temp,count=1,d=0;
	long month[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	char mon[12][10]={"JANUARY","FEBRUARY","MARCH","APRIL","MAY","JUNE","JULY","AUGUST","SEPTEMBER","OCTOBER","NOVEMBER","DECEMBER"};
	if(m<13&&m>0)
	{
		if((y%100!=0&&y%4==0)||y%400==0)
		month[2]=29;
		if(y>=2005)
		{
			temp=y-2005;
			d+=365*temp;
			for(i=2005;i<y;i++)
			{
				if((i%100!=0&&i%4==0)||i%400==0)
				d++;
			}
			for(i=0;i<m;i++)
			d+=month[i];
			d%=7;
			d--;
			if(d==-1)
			d+=7;
		}
		if(y<2005)
		{
			for(i=m;i<=12;i++)
			d+=month[i];
			temp=2004-y;
			d+=365*temp;
			for(i=y+1;i<2005;i++)
			{
				if((i%100!=0&&i%4==0)||i%400==0)
				d++;
			}
			d%=7;
			d=7-d;
			d--;
			if(d==-1)
			d+=7;
		}
		for(i=0;i<5;i++)
		{
			if(i==0)
			j=d;
			else
			j=0;
			for(;j<7&&count<=month[m];j++)
			a[i][j]=count++;
		}
		i=0;j=0;
		while(count<=month[m])
		a[i][j++]=count++;
	}
	else
	cout<<"\nInvalid Input.\n";
   cout<<"\n\n";
	cout<<"    "<<mon[m-1]<<" "<<y;
}
void Calendar::display()
{
	long i,j;
	cout<<"\nS  M  T  W  T  F  S\n";
	for(i=0;i<5;i++)
	{
		for(j=0;j<7;j++)
		{
			if(a[i][j]==0)
			cout<<"   ";
			else if(a[i][j]<10)
			cout<<a[i][j]<<"  ";
			else
			cout<<a[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"\nPROGRAM TERMINATED.";
}
void main()
{
	Calendar k;
	k.input();
	k.compute();
	k.display();
	getch();
}