#include<bits/stdc++.h>
using namespace std;

// O(n^2  * k)
int maxProfit(int prices[], int n, int k) {

	int dp[k+1][n];
	memset(dp, 0, sizeof(dp));

	for(int t=1;t<=k;t++) {
		for(int d=1;d<n;d++) {

			int profit = dp[t][d-1];

			for(int pd=0;pd<d;pd++) {          // pd - previous day
				int ptilltm1 = dp[t-1][pd];                // profit till t minus 1 transactions
				int ptth = prices[d] - prices[pd];        // profit of t th transaction

				if(ptilltm1 + ptth > profit)   {
					profit = ptilltm1 + ptth;
				}
			}
			dp[t][d] = profit;
		}
	}
	return dp[k][n-1];

}


// O(n*k)
int maxProfitOptimized(int prices[], int n, int k) {

	int dp[k+1][n];
	memset(dp, 0, sizeof(dp));

	for(int t=1;t<=k;t++) {
		int profit = INT_MIN;

		for(int d=1;d<n;d++) {

			if(dp[t-1][d-1] - prices[d-1] > profit) {
				profit = dp[t-1][d-1] - prices[d-1];
			}

			if( profit + prices[d] > dp[t][d-1]) {
				dp[t][d] = profit + prices[d];
			}
			else {
				dp[t][d] = dp[t][d-1];
			}
		}
	}
	return dp[k][n-1];
}


int main() {


	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin>>n;
	int prices[n];

	for(int i=0;i<n;i++) {
		cin>>prices[i];
	}

	int k;
	cin>>k;

	cout<<maxProfit(prices, n, k)<<endl;
	cout<<maxProfitOptimized(prices ,n, k)<<endl;


	return 0;
}




