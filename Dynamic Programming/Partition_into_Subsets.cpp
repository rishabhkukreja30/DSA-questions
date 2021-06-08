#include<bits/stdc++.h>
using namespace std;



int Counways(int n, int k) {

	if(n == 0 or k == 0 or n < k) {
		return 0;
	}

	int dp[k+1][n+1];

	memset(dp, 0, sizeof(dp));

	

	for(int i=1;i<=k;i++) {
		for(int j=1;j<=n;j++) {

			if(j < i) {
				dp[i][j] = 0;
			}
			else if(j == i) {
				dp[i][j]  =1;
			}
			else {
				dp[i][j] = dp[i-1][j-1] +  i * dp[i][j-1];
			}
		}
	}
	return dp[k][n];

}

int main() {


	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif


	int n,k;
	cin>>n>>k;

	cout<<Counways(n,k)<<endl;

	return 0;

}
