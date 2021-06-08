#include<bits/stdc++.h>
using namespace std;

int f(int n, int k) {
	if(n == 0) {
		return 1;
	}
	if(n<0) {
		return 0;
	}
	int ans = 0;
	for(int i=1;i<=k;i++) {
		ans += f(n-i, k);
	}
	return ans;
}


int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n ,k;
	cin>>n>>k;

	cout<<f(n,k);
	return 0;
}