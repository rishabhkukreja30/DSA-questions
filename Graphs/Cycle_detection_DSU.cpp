#include<bits/stdc++.h>
using namespace std;

// cycle detection in an undirected graph using dsu
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

		return findSet(parent[i], parent);
	}

	//union
	void union_set(int x, int y, int parent[]) {
		int s1 = findSet(x, parent);
		int s2 = findSet(y, parent);

		if(s1 != s2) {
			parent[s1] = s2;    // parent[s2] = s1;
		}
	}


	bool contains_cycle() {
		// DSU logic to check if graph contains cycle or not
		int *parent = new int[v];
		for(int i=0;i<v;i++) {
			parent[i] = -1;
		}

		// iterate over the edge list
		for(auto edge : l) {
			int i = edge.first;
			int j = edge.second;

			int s1 = findSet(i, parent);
			int s2 = findSet(j ,parent);

			if(s1 != s2) {
				union_set(s1, s2, parent);
			}
			else {
				cout<<"Same parents "<<s1<<" and "<<s2<<endl;
				return true;
			}
		}
		delete [] parent;
		return false;
	}

};


int main() {

	graph g(4);
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(3,0);

	cout<<g.contains_cycle()<<endl;





	return 0;
}