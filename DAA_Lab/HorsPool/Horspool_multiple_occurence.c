
#include<stdio.h>
#define SIZE 1000

int Table[SIZE];
int arr[SIZE];          //this stores the indexes where the string was found
int n=0;                // stores the number of occurences of the string

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
void Horspool(char T[],char P[])
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
            arr[n++]=i-m+1; 
			
		i=i+Table[T[i]];
	}
}

void main()
{
	printf("Enter the string\n");
	char T[SIZE],P[SIZE];
	gets(T);
	
	printf("Enter the string whose occurences are to be checked \n");
	gets(P);

    Horspool(T,P);
    if(n==0)
        printf("No occurences in the string\n");
    else
    {
        printf("The string has occured at the following indexes:");
        int i;
        for(i=0;i<n;i++)
            printf("%d ",arr[i]);
    }
    
}
