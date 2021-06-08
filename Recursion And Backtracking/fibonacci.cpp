#include<bits/stdc++.h>
using namespace std;

int fibonacci(int n) {
	//base case
	if(n==0 or n==1) {
		return n;
	}
	//recursive case
	int f1 = fibonacci(n-1);
	int f2 = fibonacci(n-2);
	return f1 + f2;
}

int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin>>n;

	cout<<fibonacci(n);


	return 0;
}
