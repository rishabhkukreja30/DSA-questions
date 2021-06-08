#include<bits/stdc++.h>
using namespace std;

    bool dfs(vector <vector <int> > &graph, int node, int color[]) {
        if(color[node] == -1) {
            color[node] = 0;
        }
        
        for(auto nbr: graph[node]) {
            if(color[nbr] == -1) {
                color[nbr] = 1 - color[node];
                int sub_prob = dfs(graph, nbr, color);
                
                if(sub_prob == false) {
                    return false;
                }
                
            }
            else if(color[nbr] == color[node]) {
                return false;
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        int color[n];
        for(int i=0;i<n;i++) {
            color[i] = -1;
        }
        
        for(int i=0;i<n;i++) {
            if(!dfs(graph, i, color)) {
                return false;
            }
        }
        
        return true;
    }


int main() {

	int n ,m;
	cin>>n>>m;

	vector <int> graph(n);
	while(m--) {
		int x, y;
		cin>>x>>y;

		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	if(dfs(graph,n)) {
		cout<<"Yes its bipartite"<<endl;
	}
	else {
		cout<<"not bipartite"<<endl;
	}

	return 0;
}



// another soln
#include <iostream>
#include<vector>
#include<unordered_map>
using namespace std;
void dfs(vector<vector<int>>& graph,unordered_map<int,bool> &visited,bool &ans,bool clr,int i)
    {
        visited[i] = clr;
        for(int j=0;j<graph[i].size();j++)
        {
            if(visited.find(graph[i][j])==visited.end())
                dfs(graph,visited,ans,!clr,graph[i][j]);
            else
            {
                if(clr == visited[graph[i][j]])
                    ans = false;
            }
        }
    }
    bool isBipartite(vector<vector<int>>& graph) {
        unordered_map<int,bool> visited;
        bool ans = true;
        for(int i=0;i<graph.size();i++)
        {
            if(visited.find(i)==visited.end())
                dfs(graph,visited,ans,true,i);
        }
        return ans;
}
int main() {
    int n; cin>>n;
    vector<vector<int>> graph;
    for(int i=0;i<n;i++){
        vector<int> temp(2);
        cin>>temp[0]>>temp[1];
        graph.push_back(temp);
    }
    cout<<isBipartite(graph);
    return 0;
}





