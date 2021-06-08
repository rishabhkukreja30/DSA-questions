#include<bits/stdc++.h>
using namespace std;

int maxProfit(int prices[], int n, int fee) {

	int obsp = -prices[0];
	int ossp = 0;

	for(int i=1;i<n;i++) {

		int nbsp = 0;
		int nssp  = 0;

		if(ossp - prices[i] > obsp) {
			nbsp = ossp - prices[i];
		}
		else {
			nbsp = obsp;
		}

		if(obsp + prices[i] - fee > ossp) {
			nssp = obsp + prices[i] - fee;
		}
		else {
			nssp = ossp;
		}

		ossp = nssp;
		obsp = nbsp;
	}
	return ossp;
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

	int fee;
	cin>>fee;

	cout<<maxProfit(prices, n, fee)<<endl;



	return 0;
}




