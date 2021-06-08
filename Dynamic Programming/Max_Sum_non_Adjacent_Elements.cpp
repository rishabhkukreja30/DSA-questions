#include<bits/stdc++.h>
using namespace std;

int max_Sum(int n, int a[]) {

	int inc = a[0];
	int exc = 0;

	for(int i=1;i<n;i++) {

		int new_inc = exc + a[i];
		int new_exc = max(inc, exc);

		inc = new_inc;
		exc = new_exc;
	}
	return max(inc, exc);
}

int max_SumDP(int n, int a[], int i, int dp[]) {

	if( i>=n) {
		return 0;
	}
	if(dp[i] != 0) {
		return dp[i];
	}

	int inc = a[i] + max_SumDP(n ,a, i+2, dp);
	int exc = max_SumDP(n ,a, i+1, dp);

	return dp[i] = max(inc, exc);

}


int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin>>n;

	int a[n];
	for(int i=0;i<n;i++) {
		cin>>a[i];
	}

	cout<<max_Sum(n, a)<<endl;


	int dp[n] = {0};

	cout<<max_SumDP(n, a, 0, dp)<<endl;


	return 0;
}