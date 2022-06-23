#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
class aeiou
{
	private:
	char a[100];
	int b[5][5];
	public:
	aeiou();
	void input();
	void compute();
	void disp();
};
aeiou::aeiou()
{
	for(int i=0;i<5;i++)
	for(int j=0;j<5;j++)
	b[i][j]=0;
	strcpy(a,"");
}
void aeiou::input()
{
	cout<<"This program is designed to display a grid which shows consequtive occurances of vowels\n"<<
	"in a string.\n\n";
	cout<<"Please enter the string. ";
	gets(a);
}
void aeiou::compute()
{
	int i,k,t,t1,l=strlen(a);
	char v[]="AEIOU";
	for(i=0;i<l;i++)
	if(a[i]>=97&&a[i]<=122)
	a[i]-=32;
	for(k=0;k<l;k++)
	for(t=0;t<5;t++)
	if(a[k]==v[t])
	for(t1=0;t1<5;t1++)
	if(a[k+1]==v[t1])
	b[t][t1]++;
}
void aeiou::disp()
{
	char v[]="AEIOU";
	cout<<"\tA\tE\tI\tO\tU\n";
	for(int i=0;i<5;i++)
	{
		cout<<v[i]<<"\t";
		for(int j=0;j<5;j++)
		cout<<b[i][j]<<"\t";
		cout<<endl;
	}
}
void main()
{
	clrscr();
	aeiou x;
	x.input();
	x.compute();
	x.disp();
	getch();
}