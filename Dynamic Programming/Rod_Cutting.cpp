#include<bits/stdc++.h>
using namespace std;

int maxProfit(int arr[], int total_len, int dp[]) {
	if(total_len == 0) {
		return 0;
	}
	if(dp[total_len] != 0) {
		return dp[total_len];
	}

	int ans  = 0;
	for(int i=1;i<=total_len;i++) {
		int net_profit = arr[i] + maxProfit(arr, total_len - i, dp);
		ans = max(ans, net_profit);
	}
	return dp[total_len] = ans;
}

int maxProfitBU(int arr[], int total_len) {
	int dp[100] = {0};

	for(int len =1; len <=total_len; len++) {
		int ans = 0;
		for(int cut =1; cut <= len; cut++) {
			ans = max(ans ,arr[cut] + dp[len -cut]);
		}
		dp[len] = ans;
	}
	return dp[total_len];

}

int  main() {

	
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int prices[100];
	int dp[100] = {0};
	int total_len;
	cin>>total_len;
	for(int i=1;i<=total_len;i++) {
		cin>>prices[i];
	}

	cout<<maxProfit(prices, total_len, dp)<<endl;
	cout<<maxProfitBU(prices, total_len)<<endl;



	return 0;
}