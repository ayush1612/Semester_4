
#include<stdio.h>
#define SIZE 1000

int Table[SIZE];

void shiftCode(char P[])
{
	int j,i;
	
	int m=strlen(P);
	for(i=0;i<SIZE;i++)
		Table[i]=m;
	
	for(j=0;j<m-1;j++)
		Table[P[j]]=m-1-j;
}

//main Algorithm
int Horspool(char T[],char P[])
{
	shiftCode(P);
	int m=strlen(P);
	int i=m-1;
	int count=0;
	while(i<strlen(T))
	{
		int k=0;
		while(k<m&&T[i-k]==P[m-1-k])
			k++;
		
		if(k==m)
            return i-m+1; 
			
		i=i+Table[T[i]];
	}
	return -1;
}

void main()
{
	printf("Enter the string\n");
	char T[SIZE],P[SIZE];
	gets(T);
	
	printf("Enter the string whose occurences are to be checked \n");
	gets(P);

	int occurence =Horspool(T,P);
	printf("Occurence at %d",occurence);
}
