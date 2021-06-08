#include<bits/stdc++.h>
using namespace std;

// O(n^3)
int minCost(int n, int c, int a[][100] ) {

	int dp[n][c];

	for(int j=0;j<c;j++) {
		dp[0][j] = a[0][j];
	}

	
	for(int i=1;i<n;i++) {
		for(int j=0;j<c;j++) {

			int cost = INT_MAX;		

			for(int k=0;k<c;k++) {
				if( k != j) {
					if(dp[i-1][k] < cost) {
						cost = dp[i-1][k];
					}
				}
			}
			dp[i][j] = a[i][j] + cost;
		}
	}

	int ans = INT_MAX;
	for(int i=0;i<c;i++) {
		if(dp[n-1][i] < ans) {
			ans = dp[n-1][i];
		}
	}
	return ans;
}


// O(n^2)
int minCostOptimized(int n, int c, int a[][100] ) {

	int dp[n][c];

	int least = INT_MAX;
	int sleast = INT_MAX;

	for(int j=0;j<c;j++) {
		dp[0][j]  = a[0][j];

		if(a[0][j] <= least) {
			sleast = least;
			least = a[0][j];
		}
		else if(a[0][j] <= sleast) {
			sleast = a[0][j];
		}
	}

	for(int i=1;i<n;i++) {

		int nleast = INT_MAX;
		int nsleast = INT_MAX;

		for(int j=0;j<c;j++) {
			if(least == dp[i-1][j]) {
				dp[i][j] = sleast + a[i][j];
			}
			else {
				dp[i][j] = least + a[i][j];
			}

			if(dp[i][j] <= nleast) {
				nsleast = nleast;
				nleast = dp[i][j];
			}
			else if(dp[i][j] <= nsleast) {
				nsleast = dp[i][j];
			}
		}
		least = nleast;
		sleast = nsleast;
	}
	return least;
}


int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n,c;
	cin>>n>>c;

	int a[100][100];

	for(int i=0;i<n;i++) {
		for(int j=0;j<c;j++) {
			cin>>a[i][j];
		}
	}

	cout<<minCostOptimized(n ,c, a)<<endl;



	return 0; 
}