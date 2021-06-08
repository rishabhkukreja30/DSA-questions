#include<bits/stdc++.h>
using namespace std;


int unboundKnapsack(int n, int weights[], int prices[], int w) {
	int dp[w+1] = {0};

	for(int i=0;i<=w;i++) {
		for(int j=0;j<n;j++) {
			if(weights[j] <= i) {
				dp[i] = max(dp[i], dp[i-weights[j]] + prices[j]);
			}
		}
	}
	return dp[w];
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

	cout<<unboundKnapsack(n , weights, prices, capacity)<<endl;

	return 0;
}