#include<bits/stdc++.h>
using namespace std;


int max_gold(int a[][100], int n, int m) {

	int dp[n][m];
	for(int j = m-1;j>=0;j--) {
		for(int i= n-1;i>=0;i--) {
			if(j == m-1) {
				dp[i][j] = a[i][j];
			}
			else if(i ==0 ) {
				dp[i][j] = a[i][j] + max(dp[i][j+1], dp[i+1][j+1]);
			}
			else if(i == n-1) {
				dp[i][j] = a[i][j] + max(dp[i][j+1], dp[i-1][j+1]);
			}
			else {
				dp[i][j] = a[i][j] + max(dp[i][j+1], max(dp[i+1][j+1], dp[i-1][j+1]));
			}
		}
	}
	int ans = dp[0][0];
	for(int i=0;i<n;i++) {
		if(dp[i][0] > ans) {
			ans = dp[i][0];
		}
	}
	return ans;
}


int main() {



	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif


	int n,m;
	cin>>n>>m;

	int a[100][100];

	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			cin>>a[i][j];
		}
	}

	cout<<max_gold(a,n,m)<<endl;



	return 0;
}