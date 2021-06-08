#include<bits/stdc++.h>
using namespace std;

int ways(int n) {

	int dp[n+1];

	dp[0] = 0;

	for(int i=1;i<=n;i++) {
		if(i >=1 and i <= 3) {
			dp[i] = 1;
		}
		else if(i == 4) {
			dp[i] = 2;
		}
		else {
			dp[i] = dp[i-1] + dp[i-4];
		}
	}
	return dp[n];
}



int main() {


	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin>>n;

	cout<<ways(n)<<endl;

	return 0;
}