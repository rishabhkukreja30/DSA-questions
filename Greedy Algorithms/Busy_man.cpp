#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int,int> p1, pair<int,int> p2) {
	return p1.second < p2.second;
}

int main() {
	

	#ifndef ONLINE_JUDGEs
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int t, n, s, e;
	cin>>t;

	vector <pair<int,int>  >v;

	while(t--) {
		cin>>n;
		for(int i=0;i<n;i++) {
			cin>>s>>e;
			v.push_back(make_pair(s,e));

		}
		// activity selection algorithm
		sort(v.begin(), v.end(), compare);

		//start picking activities
		int res  =1;
		int finish = v[0].second;

		//iterate over remaining activities
		for(int i=1;i<n;i++) {
			if(v[i].first >= finish) {
				finish = v[i].second;
				res++;
			}
		}
		cout<<res<<endl;
		v.clear();
	}

	return 0;

}