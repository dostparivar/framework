//WORDS HAVE THE SAME LENGTH THE LEXICOGRAPHICALY HIGHER ONE COMES BEFORE
#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
class StringSort
{
	private:
	char sent[101],words[10][20],temp[20];
	int i,c,n,j;
	public:
	void input();
	void compute();
	void display();
};
void StringSort::input()
{
	cout<<"This program sorts a string lexicographically.\n\n";
	cout<<"Please enter a String. ";//GETTING THE SENTENCE
	gets(sent);
   c=0,n=0;
	for(i=0;i<=strlen(sent);i++)
	{
		if(sent[i]!=' '&&sent[i]!='\0')
		words[n][c++]=sent[i];
		else
		{
			words[n][c]='\0';//CONVERING INTO STRING
			n++;
			c=0;
		}
	}
}
void StringSort::compute()
{
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{   //THE CONDITION FOR SWAPPING
			if(strlen(words[i])==strlen(words[j])&&strcmp(words[i],words[j])>0||
			strlen(words[i])>strlen(words[j]))
			{
				strcpy(temp,words[j]);
				strcpy(words[j],words[i]);
				strcpy(words[i],temp);
			}
		}
	}
	strcpy(sent,"");
	for(i=0;i<n-1;i++)
	{
		strcat(sent,words[i]);//PUTTING WORDS BACK AFTER FORMATTING
		strcat(sent," ");
	}
}
void StringSort::display()
{
	strcat(sent,words[n-1]);
	cout<<sent;//THE NEW SENTENCE
}
void main()
{
	StringSort k;
	k.input();
	k.compute();
	k.display();
	getch();
}