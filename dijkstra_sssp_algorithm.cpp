// A C++ program for Dijkstra's single source shortest path algorithm. 
// The program is for adjacency list representation of the graph
	
#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
// A utility function to find the vertex with minimum distance value, from 
// the set of vertices not yet included in shortest path tree 

vector<ll> dijkstra(vector<pll> graph[], ll n, ll src)
{
	vector<ll> dist(n + 1, LONG_MAX);
	vector<bool> visited(n + 1, false);
	priority_queue<pll, vector<pll>, greater<pll>> q;
	 // Distance of source vertex from itself is always 0 
	dist[src] = 0;
	// The output array.  dist[i] will hold the shortest 
                      // distance from src to i 
	q.push({dist[src], src});

	while(!q.empty())
	{
		ll node = q.top().second;
		q.pop();
		if(visited[node])	continue;
		
		visited[node] = true;
		for(auto adj: graph[node])
		{
			if(visited[adj.first])	continue;

			if(dist[adj.first] > dist[node] + adj.second)
			{
				dist[adj.first] = dist[node] + adj.second;
				q.push({dist[adj.first],adj.first});
			}
		}
	}

	return dist;
}


// driver program to test above function 

int main(int argc, char const *argv[])
{

	ll n = 5;
	vector<pll> graph[n + 1];
	graph[1].push_back({2, 1}); // push the edge 
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
	graph[3].push_back({4, 2});

	vector<ll> dist = dijkstra(graph, n, 1);

	for(int i = 1; i <= n; i++)
		cout<< i << " " << dist[i] << endl;

	return 0;
}