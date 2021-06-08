#include<bits/stdc++.h>
using namespace std;


int lcs(char x[], char y[]) {
	int m = strlen(x);
	int n = strlen(y);
	int dp[100][100];

	// base cases
	for(int i=0;i<=m;i++) {
		dp[i][0] = 0;
	}
	for(int j=0;j<=n;j++) {
		dp[0][j] = 0;
	}

	for(int i=1;i<=m;i++) {
		for(int j=1;j<=n;j++) {
			int q =0;
			if(x[i-1] == y[j-1]) {
				q = 1 +dp[i-1][j-1];
			}
			else {
				q = max(dp[i-1][j], dp[i][j-1]);
			}
			dp[i][j]  =q;
		}
	}
	return dp[m][n];
}

// top down 
int lcsTD(string s1 ,string s2 , int i, int j, vector<vector<int> > &dp) {
	//base case
	if(s1.length() or s2.length()) {
		return 0;
	}

	if(dp[i][j] != -1) {
		return dp[i][j];
	}

	//rec case
	if(s1[i] == s2[j]) {
		return dp[i][j] = 1 + lcsTD(s1, s2, i+1, j+1, dp);
	}

	int op1 = lcsTD(s1 ,s2, i+1, j, dp);
	int op2 = lcsTD(s1, s2, i, j+1, dp);
	return dp[i][j] = max(op1, op2);

}


int main() {


	// #ifndef ONLINE_JUDGE
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	// #endif

	// char str1[1000] , str2[1000];
	// cin>>str1>>str2;

	// cout<<lcs(str1, str2)<<endl;

	string s1 = "ABCD";
	string s2 = "ABEDG";

	int n1 = s1.length();
	int n2 = s2.length();

	vector <vector <int> > dp(n1, vector <int> (n2, -1));  // n1 x n2
	cout<<lcsTD(s1, s2, 0, 0, dp)<<endl;

	return 0;
}
