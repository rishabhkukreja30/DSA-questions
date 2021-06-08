#include<bits/stdc++.h>
using namespace std;

class graph {
	int v;
	list <pair< int, int>  > l;
public:
	graph(int v) {
		this->v = v;
	}

	int addEdge(int u, int v) {
		l.push_back(make_pair(u,v));
	}

	// Find
	int findSet(int i, int parent[]) {
		//base case
		if(parent[i] == -1) {
			return i;
		}
		// path compression optimisation
		return parent[i] = findSet(parent[i], parent);
	}

	//union
	void union_set(int x, int y, int parent[], int rank[]) {
		int s1 = findSet(x, parent);
		int s2 = findSet(y, parent);

		if(s1 != s2) {
			if(rank[s1] < rank[s2]) {
				parent[s1] = s2;
				rank[s2] += rank[s1];
			}
			else {
				parent[s2] = s1;
				rank[s1] += rank[s2];
			}
		}
	}

	int pairing() {
		// init dsu  logic
		int *parent = new int[v];
		int *rank = new int[v];

		for(int i=0;i<v;i++) {
			parent[i]  =-1;
			rank[i] = 1;
		}

		//logic
		for(auto edge : l) {
			int i = edge.first;
			int j = edge.second;

			int s1 = findSet(i ,parent);
			int s2 = findSet(j, parent);

			union_set(s1, s2, parent, rank);
		}

		// go to all the nodes
		int ans = 0;
		for(int i=0;i<v;i++) {
			ans += v - rank[findSet(i, parent)];
		}

		delete [] parent;
		delete [] rank;

		return ans/2;
	}


};


int main() {

	int n, m;
	cin>>n>>m;

	graph g(n);

	while(m--) {
		int x ,y;
		cin>>x>>y;
		g.addEdge(x, y);
	}

	cout<<pairing()<<endl;



	return 0;
}