#include<iostream.h>
#include<conio.h>
class PrimeSets
{
	private:
	int a[30],b[5],c[10];
	public:
	void Display();
	int PrimeCheck(int x);
	int RepetitionCheck();
};
int PrimeSets::PrimeCheck(int x)
{
	int i,f=1;
	for(i=2;i<=x/2;i++)
	if(x%i==0||x==1)
	f=0;
	return f;
}
int PrimeSets::RepetitionCheck()
{
	int i,j,f=1;
	for(i=0;i<5;i++)
	{
		c[i*2]=b[i]/10;
		c[i*2+1]=b[i]%10;
	}
	for(i=0;i<10;i++)
	for(j=0;j<10;j++)
	if(c[i]==c[j]&&i!=j)
	f=0;
	return f;
}
void PrimeSets::Display()
{
	int ct,i,j,k,l,m,n;
	cout<<"This program displays all the sets of 5 prime numbers which have all"<<
	" ten digits among them.";
	cout<<"\nPlease press enter to start. ";
	getch();
	cout<<"\n";
	for(i=1,ct=0;i<100;i++)
	{
		if(PrimeCheck(i))
		a[ct++]=i;
	}
	for(i=1;i<ct;i++)
	for(j=i+1;j<ct;j++)
	for(k=j+1;k<ct;k++)
	for(l=k+1;l<ct;l++)
	for(m=l+1;m<ct;m++)
	if(i!=j!=k!=l!=m)
	{
		b[0]=a[i],b[1]=a[j],b[2]=a[k],b[3]=a[l],b[4]=a[m];
		if(RepetitionCheck())
		{
			for(n=0;n<10;n+=2)
			{
				if(n!=0)
				cout<<", "<<c[n]<<c[n+1];
				else
				cout<<c[n]<<c[n+1];
			}
			cout<<"\n";
		}
	}
	cout<<"\n\nPROGRAM TERMINATED.";
}
void main()
{
	PrimeSets k;
	k.Display();
	getch();
}