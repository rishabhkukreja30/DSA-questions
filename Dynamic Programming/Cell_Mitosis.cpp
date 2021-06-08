#include<bits/stdc++.h>
using namespace std;

long long solveCellProblem(int n , int x, int y, int z) {

	long long *dp = new long long[n+1];

	//bottom up dp
	dp[0] = 0;
	dp[1] = 0; // bcoz 1 cell is given to us

	for(int i=2;i<=n;i++) {
		
		if( i%2 == 0) {
			dp[i] = min(dp[i/2] +x, dp[i-1] + y );
		}
		else {
			dp[i] = min(dp[i-1] +y, dp[(i+1)/2] + x + z);
		}
	}
	return dp[n];

}

// input: 5 2 1 3
// output: 4


int main() {


	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n ,x, y, z;
	cin>>n>>x>>y>>z;

	cout<<solveCellProblem(n,x,y,z)<<endl;

	return  0;
}