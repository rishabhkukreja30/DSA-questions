#include<bits/stdc++.h>
using namespace std;

bool BipartiteBfs(int src, vector <int> adj[], int color[]) {
	queue <int> q;
	q.push(src);
	color[src] = 1;

	while(!q.empty()) {
		int node = q.front();
		q,pop();

		for(auto nbr : adj[node])  {
			if(color[nbr] == -1) {
				color[nbr] = 1 - color[node];
				q.push(nbr);
			}
			else if(color[nbr]== color[node]) {
				return false;
			}
		}
	}

	return true;
}


bool checkBipartite(vector <int >adj[], int n) {
	int color[n];
	memset(color, -1, sizeof color);
	for(int i=0;i<n;i++) {
		if(color[i] == -1) {
			if(!BipartiteBfs(i, adj, color)) {
				return false;
			}
		}
	}
	return true;
}





int main() {

	int n,m;
	cin>>n>>m;

	vector <int> adj[n];
	for(int i=0;i<m;i++) {
		int u, v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	if(checkBipartite(adj, n)) {
		cout<<"Yes";
	}
	else {
		cout<<"No";
	}


	return 0;
}