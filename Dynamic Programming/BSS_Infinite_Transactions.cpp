#include<bits/stdc++.h>
using namespace std;

int maxProfit(int prices[], int n) {

	int bd = 0;   // buying date
	int sd = 0;   // selling date

	int profit = 0;

	for(int i=1;i<n;i++) {
		if(prices[i] > prices[i-1]) {
			sd++;
		}
		else {
			profit += prices[sd] - prices[bd];
			bd = sd = i;
		}
	}
	profit += prices[sd] - prices[bd];

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




