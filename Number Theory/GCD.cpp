#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {

	return b==0 ? a: gcd(b ,a % b);
}

int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int t;
	cin>>t;
	while(t--) {

		int a ,b;
		cin>>a>>b;
		cout<< gcd(a, b)<<endl;
	}

	return 0;
}