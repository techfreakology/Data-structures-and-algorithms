// To find distance between two nodes of a tree finding lca efficiently
#include <bits/stdc++.h>
#define MAXN 100005
#define level  18
using namespace std;

typedef long long ll; 

vector<ll> tree[MAXN]; // To store the tree's adjacency list
ll height[MAXN]; // To store the height of nodes
ll parent[MAXN][level]; // To store 2^i parent of nodes

void dfs(ll node, ll par)
{
  parent[node][0] = par;
  height[node] = height[par]+1;
  for(auto it: tree[node])
  {
    if(it!=par)
    {
      dfs(it,node);
    }
  }
}

void precompute(ll n)
{
  for(int j=1;j<level;j++)
  {
    for(int i=1;i<=n;i++)
    {
      if(parent[i][j-1]!=0)
        parent[i][j] = parent[parent[i][j-1]][j-1];
    }
  }
}

ll lca(ll u, ll v)
{
  if(height[u]>height[v])
    swap(u,v);
  ll diff = height[v] - height[u];
  for(int i=0;i<level;i++)
  {
    if((diff>>i)&1)
    {
      v = parent[v][i];
    }
  }
  if(u == v)
    return u;
  for(int i=level-1;i>=0;i--)
  {
    if(parent[u][i]!=parent[v][i])
    {
      u = parent[u][i];
      v = parent[v][i];
    }
  }
  while( u != v )
  {
      u = parent[u][0];
      v = parent[v][0];
  }
  return u;
}

ll dist(ll u, ll v)
{
  ll cp = lca(u,v);
  return height[u]+height[v]-2*height[cp];
}

int main()
{
  ll n,i,j;
  cin>>n; // No of nodes in the tree
  for(i=1;i<n;i++)
  {
    ll u,v;
    cin>>u>>v; // (u, v) is an edge in the tree
    tree[u].push_back(v);
    tree[v].push_back(u);
  }
  height[0] = 0;
  dfs(1,0);
  precompute(n);
  ll a,b;
  cin>>a>>b; // distance between node a and b
  cout << dist(a,b) <<" ";
  return 0;
}
