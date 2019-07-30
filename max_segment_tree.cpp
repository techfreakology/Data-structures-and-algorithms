#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 
typedef pair<ll,ll> pll;
 
ll getMid(ll s, ll e)  
{ 
    return s + (e - s) / 2; 
} 

ll MaxUtil(ll* st, ll ss, ll se, ll l,  
            ll r, ll node) 
{ 
    if (l <= ss && r >= se) 
        return st[node]; 
  
    if (se < l || ss > r) 
        return -1; 
  
    ll mid = getMid(ss, se); 
      
    return max(MaxUtil(st, ss, mid, l, r,  
                       2 * node + 1), 
               MaxUtil(st, mid + 1, se, l,  
                       r, 2 * node + 2)); 
} 
  
void updateValue(ll arr[], ll* st, ll ss, ll se,  
                 ll index, ll value, ll node) 
{ 
    if (index < ss || index > se)  
    { 
        return; 
    } 
      
    if (ss == se)  
    {    
        arr[index] = value; 
        st[node] = value; 
    } 
    else { 
            ll mid = getMid(ss, se); 
              
            if (index >= ss && index <= mid) 
                updateValue(arr, st, ss, mid, index,  
                            value, 2 * node + 1); 
            else
                updateValue(arr, st, mid + 1, se,  
                            index, value, 2 * node + 2); 
              
            st[node] = max(st[2 * node + 1],  
                       st[2 * node + 2]); 
    } 
    return; 
} 
  
ll getMax(ll* st, ll n, ll l, ll r) 
{ 
    if (l < 0 || r > n - 1 || l > r)  
    { 
        return -1; 
    } 
  
    return MaxUtil(st, 0, n - 1, l, r, 0); 
} 
  
ll constructSTUtil(ll arr[], ll ss, ll se,  
                    ll* st, ll si) 
{ 
    if (ss == se)  
    { 
        st[si] = arr[ss]; 
        return arr[ss]; 
    } 
  
    ll mid = getMid(ss, se); 
      
    st[si] = max(constructSTUtil(arr, ss, mid, st,  
                                 si * 2 + 1), 
                 constructSTUtil(arr, mid + 1, se,  
                                 st, si * 2 + 2)); 
      
    return st[si]; 
} 
  
ll* constructST(ll arr[], ll n) 
{ 
    // Height of segment tree 
    ll x = (ll)(ceil(log2(n))); 
  
    // Maximum size of segment tree 
    ll max_size = 2 * (ll)pow(2, x) - 1; 
  
    // Allocate memory 
    ll* st = new ll[max_size]; 
  
    // Fill the allocated memory st 
    constructSTUtil(arr, 0, n - 1, st, 0); 
  
    // Return the constructed segment tree 
    return st; 
} 


int main()
{
    ll a[] = {1,4,7,2,45,1,56,2};
    ll n = sizeof(a)/sizeof(ll);
    ll* st = constructST(a,n);

    // Maximum in range 0 to 4
    cout<<getMax(st,n,0,4)<<" "; 

    // Updating value at index 3 to 50
    updateValue(a,st,0,n-1,3,50,0);

    // Maximum in range 1 to 5
    cout<<getMax(st,n,0,4); 
    return 0;
}