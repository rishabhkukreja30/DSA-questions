#include<bits/stdc++.h>
using namespace std;


int Countstrings(int n) {

	int a[n+1] = {0};
	int b[n+1] = {0};

	a[1] = b[1] = 1;
	for(int i=2;i<=n;i++) {
		a[i] = a[i-1] + b[i-1];
		b[i] = a[i-1];
	}
	return a[n] + b[n];
}

// without using arrays - for no consecutive 0s
int CountstringsOptimized(int n) {

	int oczeros = 1;
	int ocones = 1;

	for(int i=2;i<=n;i++) {

		int nczeroes = ocones;
		int ncones = oczeros + ocones;

		oczeros = nczeroes;
		ocones = ncones;
	}
	return oczeros + ocones;
}


int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin>>n;

	cout<<Countstrings(n)<<endl;
	cout<<CountstringsOptimized(n)<<endl;


	return 0;
}