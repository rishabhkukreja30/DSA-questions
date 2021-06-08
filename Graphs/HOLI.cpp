#include<bits/stdc++.h>
using namespace std;

class graph {

	int v;
	list <pair <int, int> > *l;

public:
	graph(int v) {
		this->v = v;
		l = new list < pair <int, int > >[v];
	}

	void addEdge(int u, int v, int cost) {
		l[u].push_back(make_pair(v, cost));
		l[v].push_back(make_pair(u, cost));
	}

	int dfsHelper(int node, bool *visited, int* count, int &ans) {
		//mark the node as visited
		visited[node] = true;
		count[node]  =1;

		for(auto nbr_pair : l[node]) {
			int nbr = nbr_pair.first;
			int wt = nbr_pair.second;
			if(!visited[nbr]) {
				count[node] += dfsHelper(nbr, visited, count, ans);
				int nx = count[nbr];
				int ny = v -nx;
				ans += 2 * min(nx, ny) * wt;
			}
		}
		// just before leaving the parent node
		return count[node];

	}


	int dfs() {
		bool *visited = new bool[v];
		int  *count = new int[v];

		for(int i=0;i<v;i++) {
			visited[i] = false;
			count[i] = -1;
		}
		int ans = 0;
		dfsHelper(0, visited, count, ans);
		return ans;
	}

};




int main() {

	graph g(4);
	g.addEdge(0,1,3);
	g.addEdge(1,2,2);
	g.addEdge(2,3,2);

	cout<<g.dfs()<<endl;

	return 0;
}