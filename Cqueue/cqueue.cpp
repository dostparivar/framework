#include<iostream.h>
#include<conio.h>
#include<iomanip.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
class ceque
{
	int a[10],f,r;
	public:
		ceque();
		void push();
		void pop();
		void disp();
};
ceque::ceque()
{ f=0;r=0; }
void ceque::push()
{
	clrscr();
	if((f%10)==(r%10)&&f!=r)
		cout<<"\nfull";
	else
	{
		cout<<"Enter element : ";
		cin>>a[f%10];
		f++;
		clrscr();
	}
}
void ceque::pop()
{
	clrscr();
	if(f==r)
		cout<<"The queue is Empty.\n";
	else
		{
		cout<<"Popped element : "<<a[r]<<endl;
		r++;  }
}

void ceque::disp()
{
	clrscr();
	if(f==r)
		cout<<"The queue is Empty.\n";
	else
		for(int i=r;i<f;i++)
			cout<<a[i%10]<<" ";
	cout<<endl;
}
void main()
{
	clrscr();
	ceque x;
	int i,ch;
   cout<<"This Program implements a Circular Queue using an array.\n"; 
	do{
		cout<<"\n1.Push\n";
		cout<<"2.Pop\n";
		cout<<"3.Display\n";
		cout<<"4.Quit\n";
		cout<<"Please enter your choice : ";
		cin>>ch;
		if(ch==1) x.push();
		if(ch==2) x.pop();
		if(ch==3) x.disp();
	}while(ch!=4);
	getch();
}