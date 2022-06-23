#include<iostream.h>
#include<conio.h>
#include<iomanip.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
class evaluate
{
	private:
	char text[100];
	int s[20];
	public:
	evaluate();
	evaluate(char[]);
	void compute(char[]);
	int count;
};
evaluate::evaluate(char k[100])
{strcpy(text,k);}
evaluate::evaluate()
{
	for(int i=0;i<20;i++)
	s[i]=0;
}
void evaluate::compute(char k[100])
{
	int i,a,c,d,count=0;
	for(i=0;i<strlen(k);i++)
	{
		a=0;
		while(k[i]!=','&&k[i]!='+'&&k[i]!='-'&&k[i]!='*'&&k[i]!='/'&&k[i]!='\0')
		{
			a=a*10+(k[i]-'0');
			i++;
		}
		if(a!=0)
		s[count++]=a;
		if(k[i]=='+'||k[i]=='-'||k[i]=='*'||k[i]=='/')
		{
			c=s[--count];
			d=s[--count];
			if(k[i]=='+') s[count++]=c+d;
			if(k[i]=='-') s[count++]=d-c;
			if(k[i]=='*') s[count++]=c*d;
			if(k[i]=='/') s[count++]=d/c;
		}
	}
	cout<<s[--count];
}
void main()
{
	clrscr();
	char k[100];
	evaluate x;
	cout<<"This program is designed to evaluate a postfix expression entered by the user.\n\n";
	cout<<"Please enter the postfix expression. ";
	gets(k);
	x.compute(k);
   cout<<"\n\nPROGRAM TERMINATED.";
	getch();
}