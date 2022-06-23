#include<iostream.h>
#include<conio.h>
class MagicSquare
{
	private:
	long a[30][30],n;
	public:
	void input();
	void compute();
	void display();
};
void MagicSquare::input()
{
	clrscr();
	cout<<"This program is designed to generate a Magic Square of the order\n"<<
	"n entered by the user. The Magic Square has the sum of rows, sum of\n"<<
	"columns and the sum of diagonals are all equal.\n";
	cout<<"\nPlease enter the order of the Square. ";
	cin>>n;
	if(n==2)
	cout<<"There does not exist a magic square of order 2.";
}
void MagicSquare::compute()
{
	long i,j,count=1,r,c,m,x,count2;
	for(i=0;i<20;i++)
	for(j=0;j<20;j++)
	a[i][j]=0;
	if(n%2==1)
	{
		r=n*n,c=n*n+n/2;
		while(count<=n*n)
		{

			a[r%n][c%n]=count++;
			if((count-1)%n==0)
			r++;
			else
			r--,c++;
		}
	}
	if(n%4==0)
	{
		for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		a[i][j]=count++;
		for(i=0;i<n;i+=4)
		for(j=0;j<n;j+=4)
		for(r=0;r<4;r++)
		for(c=0;c<4;c++)
		if(r+c==n-1||r==c)
		a[i+r][j+c]=n*n+1-a[i+r][j+c];
	}
	else if(n%2==0)
	{
		m=(n-2)/4,x=n/2,count2=1;
		i=x*x,j=i+x/2;
		while(count<=n*n)
		{
			count2++;
			r=i%x,c=j%x;
			if(r<m||(r==m&&c!=m)||(r==m+1&&c==m))
			a[2*r][2*c+1]=count++,a[2*r+1][2*c]=count++,a[2*r+1][2*c+1]=count++,a[2*r][2*c]=count++;
			if((r==m+1&&c!=m)||(r==m&&c==m))
			a[2*r][2*c]=count++,a[2*r+1][2*c]=count++,a[2*r+1][2*c+1]=count++,a[2*r][2*c+1]=count++;
			if(r>m+1)
			a[2*r][2*c]=count++,a[2*r+1][2*c+1]=count++,a[2*r+1][2*c]=count++,a[2*r][2*c+1]=count++;
			if((count2-1)%x==0)
			i++;
			else
			i--,j++;
		}
	}
}
void MagicSquare::display()
{
	long i,j,x,sum=0;
	if(n==2)
	goto end;
	cout<<"\nThe Magic Square is:\n";
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			x=a[i][j];
			if(x<10)
			cout<<x<<"   ";
			else if(x<100)
			cout<<x<<"  ";
			else
			cout<<x<<" ";
		}
		sum+=a[i][--j];
		cout<<endl;
	}
	cout<<"\nThe sum of any row, column or diagonal in the square is "<<sum<<".";
   end:
	cout<<"\n\n\nPROGRAM TERMINATED.";
}
void main()
{
	MagicSquare k;
	k.input();
	k.compute();
	k.display();
	getch();
}