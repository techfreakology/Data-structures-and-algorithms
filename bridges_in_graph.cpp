#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

set<pll> ae;
vector<ll> graph[MAXN];
vector<bool> vis;
vector<ll> disc,low,par;
ll t;

void bridge(ll u)
{
    vis[u] = true;
    disc[u] = low[u] = ++t;
    for(auto it: graph[u])
    {
        if(!vis[it])
        {
            par[it] = u;
            bridge(it);
            low[u] = min(low[u],low[it]);
            
            if(low[it]>disc[u])
            {
                ae.insert({u,it});  
            }
        }
        else if(it!=par[u])
        {
            low[u] = min(low[u],disc[it]);
        }
    }
}

void reset(ll n)
{
    vis.assign(n+1,false);
    par.assign(n+1,-1);
    disc.assign(n+1,0);
    low.assign(n+1,0);
    t=0;
}


int main()
{
    ll n,m,i,j;
    cin>>n>>m;
    ll a[m+1],b[m+1];
    for(i=1;i<=m;i++)
    {
        cin>>a[i]>>b[i];
        graph[a[i]].push_back(b[i]);
        graph[b[i]].push_back(a[i]);
    }

    reset();

    
    for(i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            bridge(i);
        }
    }
    
    cout<<"Bridges in graph:\n";
    for(auto it: ae)
        cout<<it.first<<" "<<it.second<<endl;
    
    return 0;
}