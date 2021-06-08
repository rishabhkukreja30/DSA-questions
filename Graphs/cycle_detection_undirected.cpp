#include<bits/stdc++.h>
using namespace std;

class graph {

	int v;
	list <int> *l;

public:

	graph(int v){

		this->v =v;
		l = new list <int> [v];
	}

	void addEdge(int x, int y, bool  directed = true) {

		l[x].push_back(y);
		if(!directed)
			l[y].push_back(x);
	}

	bool cycle_helper(int node , bool *visited, int parent) {

		visited[node] = true;

		for(int nbr: l[node]) {

			if(!visited[nbr]){
				//go and recursuvely visit the neighbour
				bool cycle_found = cycle_helper(nbr, visited, node);
				if(cycle_found)
					return true;
			}
			//nbr is visited but nbr should not be equal to parent
			else if(nbr != parent)
				return true;
		}
		return false;

	}

	bool contains_cycle() {

		bool *visited = new bool [v];

		for(int i=0;i<v;i++) {

			visited[i] = false;
		}

		return cycle_helper(0, visited ,-1);
	}



};


int main(){

	graph g(5);

	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(3,4);
	g.addEdge(4,0);


	if(g.contains_cycle())
		cout<<"Graph has a cycle";
	else
		cout<<"Graph doesn't have a cycle";

	return 0;
}