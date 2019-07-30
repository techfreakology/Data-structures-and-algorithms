#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

vector<ll> bellman_ford(vector<pll> graph[], ll n, ll src)
{
	vector<pair<pll,ll>> edges;

	for(int i=1; i <= n; i++)
	{
		for(auto adj: graph[i])
		{
			edges.push_back({{i,adj.first},adj.second});
		}
	}

	vector<ll> dist(n+1,LONG_MAX);
	dist[src] = 0;
	for(int i = 1; i <= n-1; i++)
	{
		for(auto edge: edges)
		{
			ll u = edge.first.first,
			   v = edge.first.second,
			   w = edge.second;

			if(dist[v] > dist[u] + w)
			{
				dist[v] = dist[u] + w;
			}
		}
	}

	return dist;
}


int main(int argc, char const *argv[])
{

	ll n = 3;
	vector<pll> graph[n + 1];
	
	/*graph[1].push_back({2, 1});
	graph[1].push_back({3, 4});
	graph[2].push_back({4, 2});
	graph[2].push_back({5, 6});
	graph[3].push_back({5, 1});
	graph[4].push_back({3, 2});

	graph[2].push_back({1, 1});
	graph[3].push_back({1, 4});
	graph[4].push_back({2, 2});
	graph[5].push_back({2, 6});
	graph[5].push_back({3, 1});
	graph[3].push_back({4, 2});*/

	graph[1].push_back({2, 2});
	graph[2].push_back({1, 2});
	graph[1].push_back({3, 3});
	graph[3].push_back({1, 3});
	graph[3].push_back({2, -4});
	graph[2].push_back({3, -4});

	vector<ll> dist = bellman_ford(graph, n, 1);

	for(int i = 1; i <= n; i++)
		cout<< i << " " << dist[i] << endl;

	return 0;
}