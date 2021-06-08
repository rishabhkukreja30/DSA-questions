#include<bits/stdc++.h>
using namespace std;

int a[1000];
long long dp[1000][1000];

long long sum(int s, int e) {
	long long ans =0;
	for(int i=s;i<=e;i++) {
		ans += a[i];
		ans %= 100;
	}
	return ans;
}

long long solveMixtures(int i, int j) {
	//base case
	if(i >= j) {
		return 0;
	}
	// if the answer is already there
	if(dp[i][j] != -1) {
		return dp[i][j];
	}

	// we have to break our expression at every possible k
	dp[i][j] = INT_MAX;
	for(int k=i;k<=j;k++) {
		dp[i][j] = min(dp[i][j], solveMixtures(i,k) + solveMixtures(k+1, j) + sum(i,k) * sum(k+1,j));
	}
	return dp[i][j];
}


int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin>>n;

	for(int i=0;i<n;i++) {
		cin>>a[i];
	}

	// init dp  with -1
	for(int i=0;i<=n;i++) {
		for(int j=0;j<=n;j++) {
			dp[i][j]  =-1;
		}
	}

	cout<<solveMixtures(0 ,n-1)<<endl;


	return 0;
}