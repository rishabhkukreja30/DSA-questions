#include<bits/stdc++.h>
using namespace std;


int ladders_topdown(int n, int k ,int dp[]) {
	//base case
	if(n ==0 ){
		return 1;
	}
	//look up
	if(dp[n] != 0) {
		return dp[n];
	}

	//rec case
	int ways = 0;
	for(int i=1;i<=k;i++) {
		if(n-i >= 0) {
			ways += ladders_topdown(n-i, k, dp);
		}
	}
	return dp[n] = ways;
}

int ladders_bottomup(int n, int k) {
	int dp[100]  ={0};

	dp[0] =1; // start case
	for(int i=1;i<=n;i++) {
		dp[i] = 0;
		for(int j=1;j<=k;j++) {
			if(i -j  >= 0) {
				dp[i] +=  dp[i-j];
			}
		}
	}
	// see the bottom up
	for(int i=0;i<=n;i++ ) {
		cout<<dp[i]<<" ";
	}

	return dp[n];
}

int ladders_optimised(int n, int k) {
	int dp[100] = {0};

	dp[0]  = dp[1] = 1;
	for(int i=2;i<=k;i++) {
		dp[i] = 2*dp[i-1];
	}
	for(int i =k+1; i<=n;i++) {
		dp[i] = 2*dp[i-1] - dp[i-k-1];
	}

	//print 
	for(int i=0;i<=n;i++) {
		cout<<dp[i]<<" ";
	}
	return dp[n];
}


int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n,k;
	cin>>n>>k;

	int dp[100]=  {0};

	cout<<ladders_topdown(n,k,dp)<<endl;
	cout<<ladders_bottomup(n ,k)<<endl;
	cout<<ladders_optimised(n,k)<<endl;
	return 0;
}