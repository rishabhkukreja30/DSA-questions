#include<bits/stdc++.h>
using namespace std;

int fact(int n) {
	//base case
	if(n==0) {
		return 1;
	}
	//recursive case
	int small_ans = fact(n-1);
		return n * small_ans;
}

int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin>>n;

	cout<<fact(n);


	return 0;
}
