#include<bits/stdc++.h>
using namespace std;

int ways(int n, int m) {

	int dp[n+1];

	dp[0] = 0;

	for(int i=1;i<=n;i++) {
		if(i < m) {
			dp[i] = 1;
		}
		else if(i == m) {
			dp[i] = 2;
		}
		else {
			dp[i] = dp[i-1] + dp[i-m];
		}
	}
	return dp[n];
}



int main() {


	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n, m;
	cin>>n>>m;

	cout<<ways(n, m)<<endl;

	return 0;
}