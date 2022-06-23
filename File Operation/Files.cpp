#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<fstream.h>
class Files
{
	private:
	fstream f1,f2,f3;
	int n1,n2,n3;
	public:
	void input();
	void sort();
	void display();
};
void Files::input()
{
	clrscr();
	int i,j,roll,marks;
	n1=0,n2=0,n3=0;
	char name[100];
	cout<<"This program illustrates the usage of files to keep a record of all students\n"<<
	"of a class and sort them into passed and failed categories.";
	cout<<"\n\nPlease enter the number of students in the class. ";
	cin>>n1;
	f1.open("register.txt",ios::out);
	for(i=1;i<=n1;i++)
	{
		cout<<"\nPlease enter the name of student "<<i<<". ";
		gets(name);
		for(j=0;j<strlen(name);j++)
		if(name[j]==' ')
		name[j]='*';
		cout<<"Please enter the percentage of student "<<i<<". ";
		cin>>marks;
		cout<<"Please enter the roll number of student "<<i<<". ";
		cin>>roll;
		f1<<name<<" "<<marks<<" "<<roll<<"\n";
	}
	f1.close();
}
void Files::sort()
{
	int i,roll,marks;
	char name[100];
	f1.open("register.txt",ios::in);
	f2.open("passed.txt",ios::out);
	f3.open("failed.txt",ios::out);
	for(i=1;i<=n1;i++)
	{
		f1>>name>>marks>>roll;
		if(marks>=40)
		{
			f2<<name<<" "<<marks<<" "<<roll<<"\n";
			n2++;
		}
		else if(marks<40)
		{
			f3<<name<<" "<<marks<<" "<<roll<<"\n";
			n3++;
		}
	}
	f1.close();
	f2.close();
	f3.close();
}
void Files::display()
{
	int i,j,roll,marks;
	char name[100];
	f2.open("passed.txt",ios::in);
	f3.open("failed.txt",ios::in);
	if(n2>0)
	cout<<"\n\nThe passsed students are as follows:\n";
	for(i=1;i<=n2;i++)
	{
		f2>>name>>marks>>roll;
		for(j=0;j<strlen(name);j++)
		if(name[j]=='*')
		name[j]=' ';
		cout<<name<<"\t"<<roll<<"\t"<<marks<<".\n";
	}
   if(n3>0)
	cout<<"\n\nThe failed students are as follows:\n";
	for(i=1;i<=n3;i++)
	{
		f3>>name>>marks>>roll;
		for(j=0;j<strlen(name);j++)
		if(name[j]=='*')
		name[j]=' ';
		cout<<name<<"\t"<<roll<<"\t"<<marks<<".\n";
	}
	f2.close();
	f3.close();
   cout<<"\n\n\nPROGRAM TERMINATED.";
}
void main()
{
	Files k;
	k.input();
	k.sort();
	k.display();
}
