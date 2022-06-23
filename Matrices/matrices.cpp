/*A menu driven Program to add,subtract or multiply two arrays.*/
#include<iostream.h>
#include<conio.h>
#include<process.h>
class matrix
{
	private:
	int a[20][20],b[20][20],c[20][20],m,n,p,q,op;
	public:
	matrix();
	void input();
	void compute();
	void display();
};
matrix::matrix()
{
	int i,j;
	for(i=0;i<20;i++)
	for(j=0;j<20;j++)
	a[i][j]=0,b[i][j]=0,c[i][j]=0;
	m=0,n=0,p=0,q=0,op=0;
}
void matrix::input()
{
	int i,j;
	clrscr();
	cout<<"This Program is designed to add, subtract or multiply two matrices.\n\n";
	cout<<"Enter row and column of matrix A : ";
	cin>>m>>n;
	cout<<"Enter row and column of matrix B : ";
	cin>>p>>q;
	cout<<"\n\nEnter elements of matrix A : \n";
	for(i=0;i<m;i++)
	for(j=0;j<n;j++)
	{
		cout<<"Array element [ "<<i+1<<" , "<<j+1<<" ] :";
		cin>>a[i][j];
	}
	cout<<"\n\nEnter elements of matrix B : \n";
	for(i=0;i<p;i++)
	for(j=0;j<q;j++)
	{
		cout<<"Array element [ "<<i+1<<" , "<<j+1<<" ] :";
		cin>>b[i][j];
	}
	while(op==0)
	{
		cout<<"\n1\tAddition\n2\tSubtraction\n3\tMultiplication\n";
		cout<<"Enter the operation to be performed : ";
		cin>>op;
		if(op>3||op<1)
		{
			clrscr();
			cout<<"Invalid input...\nPlease Re-enter\n";
			op=0;
		}
	}
	if(n!=p&&op==3)
	{
		clrscr();
		cout<<":: Matrix cannot be multiplied ::";
		getch();
		exit(0);
	}
	if((m!=p||n!=q)&&op==2)
	{
		clrscr();
		cout<<":: Matrix cannot be subtracted ::";
		getch();
		exit(0);
	}
	if((m!=p||n!=q)&&op==1)
	{
		clrscr();
		cout<<":: Matrix cannot be added ::";
		getch();
		exit(0);
	}
}
void matrix::compute()
{
	int i,j,k;
	switch(op)
	{
		case 1:
		for(i=0;i<m;i++)
		for(j=0;j<q;j++)
		c[i][j]=a[i][j]+b[i][j];
		break;
		case 2:
		for(i=0;i<m;i++)
		for(j=0;j<q;j++)
		c[i][j]=a[i][j]-b[i][j];
		break;
		case 3:
		for(i=0;i<m;i++)
		for(j=0;j<q;j++)
		for(k=0;k<n;k++)
		c[i][j]+=a[i][k]*b[k][j];
		break;
	}
}
void matrix::display()
{
	int i,j,k;
	clrscr();
	for(i=0;i<m;i++)
	{
		cout<<"|\t";
		for(j=0;j<n;j++)
		cout<<a[i][j]<<"\t";
		cout<<"|"<<endl;
	}
	switch(op)
	{
		case 1:
		cout<<"\n\t   +  \n\n";
		break;
		case 2:
		cout<<"\n\t   -  \n\n";
		break;
		case 3:
		cout<<"\n\t   *  \n\n";
		break;
	}
	for(i=0;i<p;i++)
	{
		cout<<"|\t";
		for(j=0;j<q;j++)
		cout<<b[i][j]<<"\t";
		cout<<"|"<<endl;
	}
	cout<<"\n\t   =  \n\n";
	for(i=0;i<m;i++)
	{
		cout<<"|\t";
		for(j=0;j<q;j++)
		cout<<c[i][j]<<"\t";
		cout<<"|"<<endl;
	}
	getch();
}
void main()
{
	matrix k;
	k.input();
	k.compute();
	k.display();
	getch();
}