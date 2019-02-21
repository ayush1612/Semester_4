#include<stdio.h>
#include <bits/stdc++.h>
using namespace std;

int Partition(int arr[],int start,int end)
{
    int pivot=arr[end];     //last element chosen as the pivot

    //lesser elements than the pivot on the left of the pivot
    //greater elements than the pivot on the right of the pivot
    int pindex=start;
    int temp;
    for(int i=start;i<end;i++)
    {
        if(arr[i]<pivot)
        {
            //swap the pindex and the i elements 
            temp=arr[i];
            arr[i]=arr[pindex];
            arr[pindex]=temp;

            //pindex is incremented by one 
            pindex++;

        }
    }
    //now the array is partitioned. Just we need to put the pivot elemment in its required position
    //swap the pivot element with the pindex
    temp=arr[pindex];
    arr[pindex]=arr[end];
    arr[end]=temp;

    return pindex;
}

void quicksort(int arr[],int start,int end)
{
    if(start<end)
    {
        int pindex=Partition(arr,start,end);
        //sorting the elements on the left of the pindex
        quicksort(arr,start,pindex-1);

        //sorting the elements on the right of the pindex
        quicksort(arr,pindex+1,end);
    }
    //Hence Sorted
    
}


//printing the sorted array
void printArray(int arr[],int n)
{
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}

//main function to input the elements in the array and then calling the sort function accordingly
int main()
{
    int n;
    cout<<"Enter the number of elements you want to have in the array\n";
    cin>>n;

    int arr[n];             //creating  the array with n elements
    cout<<"Enter "<<n<<" elements in the array\n";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    //calling the sort fumction
    quicksort(arr,0,n-1);
    printArray(arr,n);
    return 0;
}
