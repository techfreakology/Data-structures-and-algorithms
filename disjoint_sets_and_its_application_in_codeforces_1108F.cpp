/*
This code below is implementation of methods make_set, union_sets and find_set to perform on Disjoint sets
and it's application in https://codeforces.com/contest/1108/problem/F
For solution description read editorial https://codeforces.com/blog/entry/64751
*/
#include <bits/stdc++.h>
#define MAXN 200005
#define mod 1000000007
using namespace std;
/*
 *  author  :  vivekcrux
 */
typedef long long ll; 
typedef pair<ll,ll> pll;

ll dsu[MAXN];

void make_set(ll i)
{
    dsu[i] = i;
}

void union_sets(ll i,ll j)
{
    dsu[i] = j;
}

ll find_set(ll i)
{
    if(dsu[i]==i)
        return i;
    else
        dsu[i] = find_set(dsu[i]);
    return dsu[i];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,i,j,k,m,ans=0;
    cin>>n>>m;
    map<ll,vector<pll>> edges;
    for(i=1;i<=m;i++)
    {
        ll u,v,w;
        cin>>u>>v>>w;
        edges[w].push_back({u,v});
    }
    for(i=1;i<=n;i++)
    {
        make_set(i);
    }
    for(auto it: edges)
    {
        ll good_edges = 0;
        for(auto jt: it.second)
        {
            ll a = find_set(jt.first),
               b = find_set(jt.second);
               
            if(a!=b)
            {
                good_edges++;
            }
        }
        ll merged_components = 0;
        for(auto jt: it.second)
        {
            ll a = find_set(jt.first),
               b = find_set(jt.second);
               
            if(a!=b)
            {
                union_sets(a,b);
                merged_components++;
            }
        }
        ans += good_edges - merged_components;
    }
    cout<<ans;
    return 0;
}
