#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int dp[1001][1001];


int numWays(int ro, int col) {
	//base case
	if(dp[0][0] == -1) {
		return 0;
	}

	// compute the number of ways for first row
	for(int j=0;j<col;j++) {
		
		if(dp[0][j] == -1) {
			break;
		}
		dp[0][j] = 1;
	}

	// compute the number of ways for first col
	for(int j=0;j<ro;j++) {
		
		if(dp[j][0] == -1) {
			break;
		}
		dp[j][0] = 1;
	}

	// bottom up approach for rest of the matrix
	for(int i=1;i<ro;i++) {
		for(int j=1;j<col;j++) {

			//if cell is blocked leave it
			if(dp[i][j] == -1) {
				continue;
			}

			dp[i][j]  =0;

			if(dp[i][j-1] != -1) {
				dp[i][j] = dp[i][j-1]%MOD;
			}
			if(dp[i-1][j] != -1) {
				dp[i][j] = (dp[i][j] + dp[i-1][j])%MOD;
			}
		}
	}

	// check for final cell
	if(dp[ro-1][col-1] == -1) {
		return 0;
	}
	// print the entire dp table
	// for(int i=0;i<ro;i++) {
	// 	for(int j=0;j<col;j++) {
	// 		cout<<dp[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }

	return dp[ro-1][col-1];
}

int main() {


	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	memset(dp, 0, sizeof dp);

	int m, n, p;     // m: number of rows , n: number of columns
	cin>>m>>n>>p;

	for(int i=0;i<p;i++) {
		int x, y;
		cin>>x>>y;
		//mark all blocked cells as -1
		dp[x-1][y-1] = -1;
	}

	cout<<numWays(m,n)<<endl;

	return 0;
}