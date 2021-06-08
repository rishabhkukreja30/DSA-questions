#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class graph{
	int v;
	list <int> *l;

public:

	graph(int v){

		this->v =v;
		l = new list <int> [v];
	}

	void addEdge(int x, int y){
		//directed graph
		l[x].push_back(y);
	}

	void topological_sort(){

		int *indegree = new int[v];
		for(int i=0;i<v;i++){
			indegree[i] = 0;
		}

		//update indegree by traversing edges x to y
		for(int i=0;i<v;i++){

			for(auto y : l[i]){
				indegree[y]++;
			}
		}

		//bfs
		queue <int> q;
		for(int i=0;i<v;i++){
			if(indegree[i] == 0){
				q.push(i);
			}
		}

		while(!q.empty()){
			int node  =q.front();
			cout<<node<<" ";
			q.pop();

			for(auto nbr :l[node]){
				indegree[nbr]--;
				if(indegree[nbr]==0){
					q.push(nbr);
				}
			}

		}

}

};


int main(){

	graph g(6);

	g.addEdge(2,3);
	g.addEdge(2,5);
	g.addEdge(3,5);
	g.addEdge(4,5);
	g.addEdge(0,2);
	g.addEdge(1,2);
	g.addEdge(1,4);
	

	g.topological_sort();

	return 0;
}