#include<bits/stdc++.h>
using namespace std;

template <typename T> 


class Graph{

	map < T , list <T> > l;
public:
	
	void addEdge(string x , string y){
		l[x].push_back(y);
//		l[y].push_back(x);
	}

	void dfs_helper(T src , map<T, bool> &visited , list <T> &ordering){
		//recursive function that will traverse the graph

		//cout<<src<<" ";
		visited[src] = true;
		for(T nbr :l[src]){
			if(!visited[nbr]){
				dfs_helper(nbr ,visited, ordering);
			}
		}

		ordering.push_front(src);
		return;
	}

	void dfs(){

		map <T, bool> visited;
		list <T> ordering;
		//mark all nodes as not visited in the graph
		for(auto p: l){
			T node = p.first;
			visited[node] = false;
		} 

		// call for every node
		for(auto p: l){
			T node = p.first;
			if(!visited[node]){
				dfs_helper(node, visited, ordering);
			}
		}
		
		for(auto node: ordering){
			cout<<node<<endl;
		}
	}

};


int main()
{
	Graph  <string> g;
	g.addEdge("Python", "Data Processing");
	g.addEdge("Python","Pytorch");
	g.addEdge("Python","ML");
	g.addEdge("Pytorch","Deep Learning");
	g.addEdge("Deep Learning","Face Recognition");
	g.addEdge("Data Set" , "Face Recognition");

	g.dfs();

	return 0;
}


// or


    void findTopoSort(int node, vector<int> &vis, stack<int> &st, vector<int> adj[]) {
        vis[node] = 1; 
        
        for(auto it : adj[node]) {
            if(!vis[it]) {
                findTopoSort(it, vis, st, adj); 
            }
        }
        st.push(node); 
    }


	vector<int> topoSort(int N, vector<int> adj[]) {
	    stack<int> st; 
	    vector<int> vis(N, 0); 
	    for(int i = 0;i<N;i++) {
	        if(vis[i] == 0) {
	            findTopoSort(i, vis, st, adj); 
	        }
	    }
	    vector<int> topo;
	    while(!st.empty()) {
	        topo.push_back(st.top()); 
	        st.pop(); 
	    }
	    return topo; 
	    
	}





