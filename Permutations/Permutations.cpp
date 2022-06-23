#include<iostream.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<conio.h>
class Permutations
{
	private:
	long l,c,t[10];
	char a[10],str[360][7];
	public:
	Permutations();
	long tRepetitions();
	long aRepetitions();
	void input();
	void display();
};
Permutations::Permutations()
{
	long i,j;
	l=0,c=0;
	for(i=0;i<10;i++)
	{
		a[i]='\0',t[i]=0;
		for(j=0;j<360;j++)
		if(i<7)
		str[j][i]='\0';
	}
}
void Permutations::input()
{
	clrscr();
	cout<<"This program is designed to display all possible permutations of a"<<
	"\nword entered by the user upto 6 letters of length if there are repetitions.";
	cout<<"\n\nPlease enter the string. ";
	cin>>a;
	l=strlen(a);
}
long Permutations::tRepetitions()
{
	long i,j;
	for(i=0;i<l;i++)
	for(j=0;j<l;j++)
	if(t[i]==t[j]&&j!=i)
	return 0;
	return 1;
}
long Permutations::aRepetitions()
{
	long i,j;
	for(i=0;i<l;i++)
	for(j=0;j<l;j++)
	if(a[j]==a[i]&&j!=i)
	return 0;
	return 1;
}
void Permutations::display()
{
	long i=0,j,temp,f,count=0;
	char cp[10]={'\0'};
	cout<<"\nThe possible permutations of the word are:\n";
	while(i<pow(l,l))
	{
		temp=i,f=1;
		for(j=0;temp!=0;j++)
		{
			t[j]=temp%l;
			temp/=l;
		}
		f=tRepetitions();
		i++;
		if(f==0)
      continue;
		if(f==1)
		{
			for(j=0;j<l;j++)
			cp[j]=a[t[j]];
			if(aRepetitions()==0)
			{
				for(j=0;j<c;j++)
				if(strcmp(cp,str[j])==0)
				f=0;
				if(f==1)
				strcpy(str[c++],cp);
			}
			else
			{
				cout<<cp<<"\t";
				c++;
			}
		}

	}
	if(aRepetitions()==0)
	for(i=0;i<c;i++)
	cout<<str[i]<<"\t";
   cout<<"\n\nThere are "<<c<<" permutations of the word.";
	cout<<"\n\nPROGRAM TERMINATED.";
}
void main()
{
	Permutations k;
	k.input();
	k.display();
	getch();
}