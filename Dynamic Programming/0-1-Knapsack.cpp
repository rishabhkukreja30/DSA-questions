#include<bits/stdc++.h>
using namespace std;

// top down dp
int knapsack(int n, int weights[], int prices[], int capacity, int dp[][100]) {

	if(n ==0 or capacity == 0) {
		return 0;
	}
	if(dp[n][capacity] != -1) {
		return dp[n][capacity];
	}

	int include = 0;
	int exclude = 0;

	// include the current element
	if(weights[n-1] <= capacity) {
		include = prices[n-1] + knapsack(n-1,weights, prices, capacity - weights[n-1], dp);
	}
	// exclude the current eleemnt
	exclude = knapsack(n-1,weights, prices, capacity, dp);

	dp[n][capacity] = max(include, exclude);
	return dp[n][capacity];
}

// bottom up approach
int knapsackBU(int n, int weights[], int prices[], int capacity) {
	
	int dp[n+1][capacity+1];
	memset(dp, -1, sizeof(dp));

	for(int i=0;i<=n;i++) {
		for(int j=0;j<=capacity;j++) {

			if(i ==0 or j == 0) {
				dp[i][j] = 0;
			}
			else if(weights[i-1] <= j) {
				dp[i][j] = max(prices[i-1] + dp[i-1][j- weights[i-1]], dp[i-1][j]);
			}
			else {
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	return dp[n][capacity];

}


int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin>>n;

	int weights[n];
	int prices[n];

	for(int i=0;i<n;i++) {
		cin>>weights[i];
	}
	for(int i=0;i<n;i++) {
		cin>>prices[i];
	}

	int capacity;
	cin>>capacity;

	int dp[100][100];
	memset(dp , -1, sizeof(dp));

	// cout<<knapsack(n, weights, prices, capacity, dp)<<endl;
	cout<<knapsackBU(n , weights, prices, capacity)<<endl;
	return 0;
}