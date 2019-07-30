#include <bits/stdc++.h>
#define inf LLONG_MAX/3
using namespace std;

typedef long long ll; 
typedef pair<ll,ll> pll;
 
ll getMid(ll s, ll e)  
{ 
    return s + (e - s) / 2; 
} 

ll Util(ll* st, ll ss, ll se, ll l,  
            ll r, ll node) 
{ 
    if (l <= ss && r >= se) 
        return st[node]; 
  
    if (se < l || ss > r) 
        return inf; 
  
    ll mid = getMid(ss, se); 
      
    return min(Util(st, ss, mid, l, r,  
                       2 * node + 1), 
               Util(st, mid + 1, se, l,  
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
              
            st[node] = min(st[2 * node + 1],  
                       st[2 * node + 2]); 
    } 
    return; 
} 
  
ll get(ll* st, ll n, ll l, ll r) 
{ 
    if (l < 0 || r > n - 1 || l > r)  
    { 
        return inf; 
    } 
  
    return Util(st, 0, n - 1, l, r, 0); 
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
      
    st[si] = min(constructSTUtil(arr, ss, mid, st,  
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

    // Minimum in range 0 to 4
    cout<<get(st,n,0,4)<<" "; 

    // Updating value at index 3 to 0
    updateValue(a,st,0,n-1,3,0,0);

    // Minimum in range 1 to 5
    cout<<get(st,n,0,4); 
    return 0;
}