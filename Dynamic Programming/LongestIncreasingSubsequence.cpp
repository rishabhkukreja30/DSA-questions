#include<bits/stdc++.h>
using namespace std;


int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin>>n;

	int a[n];

	for(int i=0;i<n;i++) {
		cin>>a[i];
	}

	int dp[n] = {};

	for(int i=0;i<n;i++) {
		dp[i]  =1;    // every element can end at length 1
		for(int j=0;j<i;j++) {
			if(a[j] < a[i]) {
				dp[i] = max(dp[i], dp[j] +1);
			}
		}
	}

	int lis = 0;
	for(int i=0;i<n;i++) {
		//cout<<dp[i]<<" ";
		lis = max(lis, dp[i]);
	}

	cout<<lis<<endl;






	return 0;
}