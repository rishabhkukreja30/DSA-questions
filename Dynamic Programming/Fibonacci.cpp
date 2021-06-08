#include<bits/stdc++.h>
using namespace std;

// Top Down Approach
int fib(int n, int dp[]) {
	//Base case 
	if(n ==0 || n == 1) {
		return n;
	}
	// Recursive
	// Look Up
	if(dp[n] != 0) {
		return dp[n];
	}
	int ans;
	ans = fib(n-1, dp) + fib(n-2, dp);
	return dp[n] = ans;
}

// Bottom up Approach
int fibBU(int n) {
	int dp[100] = {0};
	dp[1]  =1;

	for(int i=2;i<=n;i++) {
		dp[i] = dp[i-1] + dp[i-2];
	}
	return dp[n];
}


// Top Down Approach with space optimisation
int fibSpaceOpt(int n)  {
	if(n==0 or n==1) {
		return n;
	}
	int a = 0;
	int b = 1;
	int c;
	for(int i=2;i<=n;i++) {
		c = a + b;
		a = b;
		b = c;
	}
	return c;
}


int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin>>n;
	int dp[100] = {0};


	cout<<fib(n,dp)<<endl;
	cout<<fibBU(10)<<endl;
	return 0;
}