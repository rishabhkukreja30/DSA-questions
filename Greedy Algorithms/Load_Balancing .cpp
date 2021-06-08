#include<bits/stdc++.h>
using namespace std;



int main() {


	#ifndef ONLINE_JUDGEs
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int arr[9000];
	int n, i, t, diff;
	cin>>t;


	while(t--) {
		//take input current test case
		int max_load = 0, load = 0;
		cin>>n;
		//stop taking input if n= -1
		if(n == -1) {
			break;
		}
		for(int i=0;i<n;i++) {
			cin>>arr[i];
			load += arr[i];
		}
		// check if load is an integer or not
		if(load % n != 0) {
			cout<<"-1"<<endl;
			continue;
		}


		//find the load that is to be divided equally
		load  = load /n;

		//greedy step
		for(int i=0;i<n;i++) {
			//find the difference between final load to be assigned and current load
			diff += (arr[i] - load);
			int ans = max(diff , -diff);
			max_load = max(max_load, ans);

		}
		cout<<max_load<<endl;
	}
	return 0;
}