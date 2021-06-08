#include<bits/stdc++.h>
using namespace std;



int main() {
	

	#ifndef ONLINE_JUDGEs
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int arr[100000] = {0};
	int t;
	cin>>t;

	while(t--) {
		memset(arr, 0, sizeof(arr));
		string name;
		int n, rank;
		cin>>n;
		for(int i=0;i<n;i++) {
			cin>>name>>rank;
			arr[rank]++;
		}

		//greedy approach - assign the nearest rank available
		int actual_rank = 1;
		int sum = 0;
		for(int i=1;i<=n;i++) {

			while(arr[i]) {
				sum += abs(actual_rank - i);
				arr[i]--;
				actual_rank++;
			}	
		}
		cout<<sum<<endl;

	}


	return 0;
}