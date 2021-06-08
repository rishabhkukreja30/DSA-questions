#include<bits/stdc++.h>
using namespace std;

int maxProfit(int prices[], int n) {

	int mpist = 0;    // max profit if sold today
	int lsf = prices[0];   // least so far

	int dp[n] = {0};

	for(int i=1;i<n;i++) {
		if(prices[i] < lsf) {
			lsf = prices[i];
		}

		mpist = prices[i] - lsf;

		if(mpist > dp[i-1]) {
			dp[i] = mpist;
		}
		else {
			dp[i] = dp[i-1];
		}
	}

	int mpibt = 0;  // max profit if bought today 
	int maxat = prices[n-1];   // max after today

	int dpr[n] = {0};

	for(int i = n-2; i>=0;i--) {
		if(prices[i] > maxat) {
			maxat = prices[i];
		}

		mpibt = maxat - prices[i];
		if(mpibt > dpr[i+1]) {
			dpr[i] = mpibt;
		}
		else {
			dpr[i] = dpr[i+1];
		}
	}

	int profit = 0;
	for(int i=0;i<n;i++) {
		if(dp[i] + dpr[i] > profit) {
			profit = dp[i] + dpr[i];
		}
	}

	return profit;
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

	cout<<maxProfit(prices, n)<<endl;



	return 0;
}




