#include<stdio.h>
#include<time.h>

/*PROCESS:
* Create a pivot element 
* Partition the array in such a way that the pivot element comes to its position it will have after being sorted.
* Recursively perform the process to sort the rest of the array.
*/

int partition(int arr[],int start,int end){
    
    //taking last element as the pivot
    int pivot=arr[end];

    int i=start,pindex=start;
    int temp;           //temporary variable to swap the elements 
    while(i<end)
    {
        if(pivot>arr[i])
        {
            //swapping the elememts if it is greater than the pivot 
            temp=arr[i];
            arr[i]=arr[pindex];
            arr[pindex]=temp;

            //incrementing the value of pindex
            pindex++;
        }
        i++;
    }
    
    //swapped the pivot element in order to bring it to the position it will have after being sorted
    temp=arr[pindex];
    arr[pindex]=arr[end];
    arr[end]=temp;

    return pindex;
}

void quickSort(int arr[],int start,int end)
{
    if(start<end)
    {
        int pindex = partition(arr,start,end);

        //sorting the left part of the array and then he right part
        quickSort(arr,start,pindex-1);
        quickSort(arr,pindex+1,end);
    }
}
/*
void printArray(int arr[],int n)
{
    //displaying the array
    int i=0;
    for(;i<n;i++)
        printf("%d ",arr[i]);
}
*/
//main function
void main()
{
    int arr[100000];
    int n;
    printf("Ente the number of elements you want to have in the array\n");
    scanf("%d",&n);

    // printf("Enter the elements in the array\n");
    int i=0;
    for(;i<n;i++)
        // scanf("%d",&arr[i]);
        arr[i]=rand();
    clock_t start,end;

    start=clock();
    quickSort(arr,0,n-1);
    end=clock();

    double time = (double)(end-start)/CLOCKS_PER_SEC;
    printf("Time taken=%f",time);
    // printArray(arr,n);
}
