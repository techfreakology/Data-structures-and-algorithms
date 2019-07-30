#include <iostream>
#include <algorithm>
using namespace std;

/*Implementation of lower_bound function
/*Returns index of the first element in the range [s,e] which 
does not compare less than val.
Array must be sorted
*/
int lower_bound(int arr[],int s,int e,int val)
{
    if(s<e)
    {
        int mid = (s+e)/2;
        if(arr[mid] == val)
            return mid;
        else if(arr[mid]>val)
        {
            return lower_bound(arr,s,mid,val);
        }
        else
        {
            return lower_bound(arr,mid+1,e,val);
        }
    }
    if(s==e)
    {
        if(arr[s]>=val) return s;
        else    return s+1;
    }
}

/*Implementation of upper_bound function
Returns index of the first element in the range [s,e] which 
compares greater than val.
Array must be sorted
*/
int upper_bound(int arr[],int s,int e,int val)
{
    if(s<e)
    {
        int mid = (s+e)/2;
        if(arr[mid] == val)
            return mid+1;
        else if(arr[mid]>val)
        {
            return upper_bound(arr,s,mid,val);
        }
        else
        {
            return upper_bound(arr,mid+1,e,val);
        }
    }
    if(s==e)
    {
        return s+1;
    }
}

int main()
{
    int n=8,i,j,a[]={1,2,2,3,4,5,7,9};

    cout<<a[lower_bound(a,0,n-1,6)]<<endl;
    cout<<a[upper_bound(a,0,n-1,3)]<<endl;
    return 0;
}
