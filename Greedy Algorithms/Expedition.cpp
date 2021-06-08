#include<bits/stdc++.h>
using namespace std;

bool compare(pair <int,int> p1, pair <int,int> p2) {
	return p1.first > p2.first;
}


int main()  {

	
	#ifndef ONLINE_JUDGEs
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n, t, x ,d, f, D,F, prev =0;
	cin>>t;
	while(t--) {

		int flag =0, ans =0;
		vector< pair <int,int> > v;
		priority_queue<int> pq;

		cin>>n;

		for(int i=0;i<n;i++) {
			cin>>d>>f;
			v.push_back(make_pair(d,f));

		}


		//logic
		sort(v.begin(), v.end(), compare);

		cin>>D>>F;

		//update the distance of fuel station from the truck
		for(int i=0;i<n;i++) {
			v[i].first = D - v[i].first;
		}

		// prev denotes the prev city we have visited
		prev = 0;
		x = 0; //current city

		while(x<n) {
			//if we have enough fuel to go to next city
			if(F >= (v[x].first - prev)) {
				F = F - (v[x].first - prev);
				pq.push(v[x].second);
				prev = v[x].first;
			}
			else {
				//check if you have some fuelling station visited in the priority queue
				if(pq.empty()) {
					flag =1;
					break;
				}

				//otherwise refuel the trucks with fuel stations with higher capacity
				F += pq.top();
				//remove that fuel station from pq
				pq.pop();
				ans = ans + 1;
				continue;
			}
			x++;
		}
		//actually travelled through n fuel stations
		//now you have to reach the town from last fuel station

		if(flag == 1) {
			cout<<"-1"<<endl;
			continue;
		}
		//otherwise
		D = D - v[n-1].first;
		if(F >= D) {
			cout<<ans<<endl;
			continue;
		}

		//otherwise
		while(F< D) {
			if(pq.empty()) {
				flag = 1;
				break;
			}

			F += pq.top();
			pq.pop();
			ans = ans + 1;
		}

		if(flag == 1) {
			cout<<"-1"<<endl;
		}
		cout<<ans<<endl;
	}







	return 0;
}