#include<bits/stdc++.h>
using namespace std;

class graph {

	// adjacency list
	vector <pair <int, int > > *l;
	int v;

public:
	graph(int n) {
		v = n;
		l = new vector <pair <int, int> > [n];
	}

	void addEdge(int x, int y, int w) {
		l[x].push_back({y,w});
		l[y].push_back({x,w});
	}

	int prim_mst() {
		// init a min heap
		priority_queue < pair <int, int> , vector <pair <int, int > >, greater< pair <int, int > > > q;

		//visited array that denotes whether a node has been included in MST or not
		bool *visited = new bool[v]{0};
		int ans = 0;

		q.push({0,0});  // weight, node   so that sorting is done on basis of weight

		while(!q.empty()) {
			// pick out the edge with min weight
			auto best = q.top();
			q.pop();

			int to = best.second;
			int weight = best.first;

			if(visited[to]) {
				// discard the edge and continue
				continue;
			}

			//otherwise take the current edge
			ans += weight;
			visited[to] = 1;

			// add the new edges in the queue
			for(auto x: l[to])  {
				if(visited[x.first] == 0) {
					q.push({x.second, x.first});
				}
			}
		}
		return ans;
	}
};


int main() {


	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n, m;
	cin>>n>>m;

	graph g(n);
	for(int i=0;i<m;i++) {
		int x, y,w;
		cin>>x>>y>>w;
		g.addEdge(x-1,y-1,w);         
	}

	cout<<g.prim_mst()<<endl;

	return 0;
}