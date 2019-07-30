#include <bits/stdc++.h>
using namespace std;

//swap function to swap two elements
void swap(int &l,int &u)
{
    int t=l;
    l=u;
    u=t;
}

//quickSort recursive function definition
void quickSort(int arr[],int start,int end)
{
    /*if start is less than end i.e number of 
    elements in the interval [start,end] is greater than 1.
    In this case we can partition the array arround a pivot element
    */
    if(start<end)
    {
        //selesting the last element as pivot element
        int pivot = arr[end],i,j;
        
        //initialized index to put the pivot element  
        j = start - 1;
        
        /*finding the currect position for placing pivot element
        and also swaping smaller elements with current elements 
        so that all the elements less than(or equal to) pivot 
        element come on left of the pivot element index
        */
        for(i=start;i<end;i++)
        {
            if(arr[i]<=pivot)
            {
                j++;
                swap(arr[i],arr[j]);
            }
        }
        
        /*finally swap the pivot element with found correct 
        position of pivot
        */
        swap(arr[j+1],arr[end]);
        
        //recursive call to left subarray
        quickSort(arr,start,j);
        
        //recursive call to right subarray
        quickSort(arr,j+2,end);
    }    
}

int main()
{
    int arr[100001],n,i;
    
    //size of input array
    cin>>n;
    
    //input array
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    //call to quick sort recursive function
    //quickSort(array,start index,end index)
    quickSort(arr,0,n-1);
    
    //sorted array
    for(i=0;i<n;i++)
    cout<<arr[i]<<" ";
    
    return 0;
}
