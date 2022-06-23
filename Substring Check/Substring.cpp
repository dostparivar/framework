#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
class Substring
{
	private:
	char a[100],b[100],c[100];
	long l1,l2,l3;
	public:
	Substring();
	void input();
	void compute();
	void display();
};
Substring::Substring()
{
	long i;
	for(i=0;i<100;i++)
	a[i]='\0',b[i]='\0',c[i]='\0';
	l1=0,l2=0,l3=0;
}
void Substring::input()
{
	cout<<"This program finds the largest common substring from the two strings"<<
	"\nentered by the user.";
	cout<<"\n\nPlease enter the first string. ";
	gets(a);
	cout<<"Please enter the second string. ";
	gets(b);
	l1=strlen(a),l2=strlen(b);
}
void Substring::compute()
{
	long i,j,k,m,tl=0,f;
	char temp[100]={'\0'};
	for(i=0;i<l1;i++)
	{
		for(j=i;j<l1;j++)
		{
			for(m=0;m<100;m++)
			temp[m]='\0';
			tl=0;
			for(m=i;m<=j;m++)
			temp[tl++]=a[m];
			temp[tl]='\0';
			for(m=0;m<l2;m++)
			{
				f=0;
				if(b[m]==temp[0])
				{
            	f=1;
					for(k=0;k<tl;k++)
					if(b[m+k]!=temp[k])
					f=0;
				}
				if(f==1&&tl>l3)
				{
					strcpy(c,temp);
					l3=tl;
				}
			}
		}
	}
}
void Substring::display()
{
	cout<<"\n\nThe largest common substring is "<<c<<".";
	cout<<"\n\n\nPROGRAM TERMINATED.";
}
void main()
{
	Substring k;
	k.input();
	k.compute();
	k.display();
	getch();
}