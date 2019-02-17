#include<stdio.h>
#include<time.h>
#include<math.h>

/* ## PROCESS:
    * dividing the original array into two arrays continuously until we get single element as an array.
    * merging the two most basic components such that the smaller element comes before the larger one (ascending order)
*/

void merge(int arr[],int l,int m,int r)
{
    int n1=m-l+1;                   //number of elements in the left array
    int n2=r-m;                     //number of elements in the right array
    int L[n1];                      //temporary array to take the left array
    int R[n2];                      //temporary array to take the right array

    int i,j,k;                      

    //adding elements into the left array
    for(i=0;i<n1;i++)
        L[i]=arr[l+i];
    
    //adding elements into the right array
    for(i=0;i<n2;i++)
        R[i]=arr[m+i+1];

    i=0,j=0,k=l;
    while(i<n1&&j<n2)
    {
        if(L[i]>R[j])
            arr[k++]=R[j++];
        else
            arr[k++]=L[i++];
    }

    //if R[] finished before L[] and there are still elements in the array R[]
    //Adding the rest of the elements in the arr[]
    while(j<n2)
        arr[k++]=R[j++];
    
    //if L[] finished before L[] and there are still elements in the array L[]
    //Adding the rest of the elements in the arr[]
    while(i<n1)
        arr[k++]=L[i++];
}

//sorting the elements using recursive function
void mergeSort(int arr[],int l,int r)
{
    if(l<r)
    {
        int m=(l+r)/2;
        
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        //merging the two subarrays
        merge(arr,l,m,r);   
    }
}

//main function
void main()
{
    int i;                  //loop variable
    int n;                  //the number of elemennts in the array
    int arr[1000000];           //original array

    clock_t start,end;      //clock variables

    printf("Enter the number of elements you want in the array\n");
    scanf("%d",&n);    

    //entering the elements in the array
    for(i=0;i<n;i++)
        arr[i]=rand();

    start=clock();          //clock start
    mergeSort(arr,0,n-1);
    end=clock();            //clock ends

    //calculating the time by taking out difference between the start and end time
    double time=(double)(end-start)/CLOCKS_PER_SEC;     

    printf("Time taken for %d instructions= %f\n",n,time);
}