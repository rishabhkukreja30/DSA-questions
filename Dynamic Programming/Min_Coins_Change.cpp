#include<bits/stdc++.h>
using namespace std;

int minCoins(int n, int coins[], int T, int dp[]) {
	// base case
	if(n ==0 ) {
		return 0;
	}
	// look up
	if(dp[n] != 0) {
		return dp[n];
	}
	// rec case
	int ans = INT_MAX;
	for(int i=0;i<T;i++) {
		if(n - coins[i] >= 0) {
			int subprob =  minCoins(n-coins[i], coins ,T, dp);
			ans = min(ans, subprob+1);
		}
	}
	dp[n] = ans;
	return dp[n];

}


// botttom up approach
int minCoinsBU(int N, int coins[], int T) {
	int dp[100] = {0};

	// iterate over all the states 1 .... n
	for(int n=1;n<=N;n++) {
		// init the current ans as int_max
		dp[n] = INT_MAX;

		for(int i=0;i<T;i++) {
			if(n-coins[i] >= 0) {
				int subprob = dp[n - coins[i]];
				dp[n] = min(dp[n], subprob +1);
			}
		}
	}
	return dp[N];
}

int main() {

	// #ifndef ONLINE_JUDGE
	// freopen(".input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	// #endif

	int N =15;
	int coins[]  = {1,7,10};

	int dp[100] = {0};
	int T = sizeof(coins)/ sizeof(int);

	cout<<minCoins(N, coins, T, dp)<<endl;
	cout<<minCoinsBU(N,coins, T)<<endl;



	return 0;
}