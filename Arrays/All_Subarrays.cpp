#include<bits/stdc++.h>
using namespace std;



int main()  {

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin>>n;

	int a[1000];

	
	for(int i=0;i<n;i++) {
		cin>>a[i];
	}

	//generate all subarrays
	for(int i=0;i<n;i++) {
		for(int j=i;j<n;j++) {
			//elements of subarray(i,j)
			for(int k=i;k<=j;k++) {
				cout<<a[k]<<" ";
			}
			cout<<endl;
		}
	}


	return 0;
}