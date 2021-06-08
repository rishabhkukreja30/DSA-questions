#include<bits/stdc++.h>
using namespace std;


int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	//allocation + deallocation = compiler
	int b[100];
	cout<<sizeof(b)<<endl;

	//dynamic allocation
	int n;
	cin>>n;
	int *a = new int[n];
	cout<<sizeof(a)<<endl;

	for(int i=0;i<n;i++) {
		cin>>a[i];
		cout<<a[i]<<" ";
	}

	// free up space
	delete [] a;


	return 0;
}