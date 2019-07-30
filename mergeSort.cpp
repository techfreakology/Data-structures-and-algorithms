#include <bits/stdc++.h>
using namespace std;


//merge function to merge two sorted arrays
void merge(int A[],int s,int e)
{
    int mid = (s+e)/2;
    int i = s, j = mid+1;
    vector<int> temp;
    while(i<=mid && j<=e)
    {
        if(A[i]<=A[j])
        {
            temp.push_back(A[i]);
            i++;
        }
        else
        {
            temp.push_back(A[j]);
            j++;
        }
    }
    while(i<=mid)
    {
        temp.push_back(A[i]);
        i++;
    }
    while(j<=e)
    {
        temp.push_back(A[j]);
        j++;
    }
    for(i=s;i<=e;i++)
    {
        A[i] = temp[i-s];
    }
}


/*
mergeSort function recursively call its left half and 
right half and the call merge function to merge the two
sorted halves
*/
void mergeSort(int arr[],int s,int e)
{
    if(s==e)    
        return;
    int mid = (s+e)/2;
    mergeSort(arr,s,mid);
    mergeSort(arr,mid+1,e);
    merge(arr,s,e);
}

int main()
{
    int n,a[100001],i;
    //size of the input array
    cin>>n;

    //input array
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    
    /*
    calling mergeSort on input array
    mergeSort(array,start,end)
    */
    mergeSort(a,0,n-1);
    
    //sorted array
    for(i=0;i<n;i++)    cout<<a[i]<<" ";
    
    return 0;
}
