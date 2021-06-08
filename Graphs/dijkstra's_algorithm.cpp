#include<bits/stdc++.h>
using namespace std;

template <typename t>
class graph{

	unordered_map < t, list <pair <t, int > > > m;
public:

	void addEdge(t u, t v, int dist, bool bidir = true) {
		m[u].push_back(make_pair(v, dist));
		if(bidir) {
			m[v].push_back(make_pair(u,dist));
		}
	}

	void printAdj() {

		for(auto j : m) {
			cout<<j.first<<"->";
			for(auto l : j.second) {
				cout<<"("<<l.first<<","<<l.second<<")";
			}
			cout<<endl;
		}
	}

	void dijkstraSSSP(t src) {

		unordered_map <t, int> dist;
		//set all distance to infinity
		for(auto j: m) {
			dist[j.first] = INT_MAX;
		}

		//make a set to find out a node with minimum distance
		set < pair <int , t> > s;

		dist[src] = 0;
		s.insert(make_pair(0,src));

		while(!s.empty()) {

			//find the pair at the front
			auto p = *(s.begin());
			t node = p.second;

			int nodeDist = p.first;
			s.erase(s.begin());

			//iterate over neighbour/children of current node
			for(auto childPair :m[node]) {

				if(nodeDist + childPair.second < dist[childPair.first]) {

					//in the set updation of a particular node is not possible
					//we have to remove the old pair and insert the new pair to simulate insertion
					t dest = childPair.first;
					auto f = s.find(make_pair(dist[dest], dest));
					if(f!=s.end()) {
						s.erase(f);
					}

					//insert the new pair
					dist[dest] = nodeDist + childPair.second;
					s.insert(make_pair(dist[dest], dest));
				}
			}
		}

		//print dist to all other nodes from source
		for(auto d:dist) {
			cout<<d.first<<" is located at a distance of "<<d.second<<endl;
		}
	}


};

int main() {

	graph  <int> g;

	g.addEdge(1,2,1);
	g.addEdge(1,3,4);
	g.addEdge(2,3,1);
	g.addEdge(3,4,2);
	g.addEdge(1,4,7);
	g.printAdj();
	g.dijkstraSSSP(1);

	return 0;
}



#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m,source;
	cin >> n >> m;
	vector<pair<int,int> > g[n+1]; 	// 1-indexed adjacency list for of graph

	int a,b,wt;
	for(int i = 0; i<m ; i++){
		cin >> a >> b >> wt;
		g[a].push_back(make_pair(b,wt));
		g[b].push_back(make_pair(a,wt));
	}	
	
	cin >> source;
	
	// Dijkstra's algorithm begins from here
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;// min-heap ; In pair => (dist,from)
	vector<int> distTo(n+1,INT_MAX); 	// 1-indexed array for calculating shortest paths; 
	
	distTo[source] = 0;
	pq.push(make_pair(0,source));	// (dist,from)
	
	while( !pq.empty() ){
		int dist = pq.top().first;
		int prev = pq.top().second;
		pq.pop();
		
		vector<pair<int,int> >::iterator it;
		for( it = g[prev].begin() ; it != g[prev].end() ; it++){
			int next = it->first;
			int nextDist = it->second;
			if( distTo[next] > distTo[prev] + nextDist){
				distTo[next] = distTo[prev] + nextDist;
				pq.push(make_pair(distTo[next], next));
			}
		}
		
	}
	
	cout << "The distances from source, " << source << ", are : \n";
	for(int i = 1 ; i<=n ; i++)	cout << distTo[i] << " ";
	cout << "\n";
	
	return 0;
}

















