#include<bits/stdc++.h>
using namespace std;

void insertion_sort(int a[], int n) {
	for(int i=1;i<n;i++) {
		int key = a[i] ;
		//place the current element in right position in the sorted part
		int j =i-1;
		while(j>=0 and a[j] > key) {
			a[j+1]  = a[j];
			j= j-1;
		}
		a[j+1] = key;
	}
	return;
}




int main()  {

	#ifndef ONLINE_JUDGEs
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n, key;
	cin>>n;

	int a[1000];

	for(int i=0;i<n;i++) {
		cin>>a[i];
	}

	insertion_sort(a,n);

	for(int i=0;i<n;i++) {
		cout<<a[i]<<" ";
	}	

	return 0;
}