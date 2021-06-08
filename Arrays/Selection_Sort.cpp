#include<bits/stdc++.h>
using namespace std;

void selection_sort(int a[], int n) {
	for(int i=0;i<n-1;i++) {
		//find out the smallest element in the unsorted part
		int min_index = i;
		for(int j=i;j<=n-1;j++) {
			if(a[j] < a[min_index]) {
				min_index  =j;
			}
		}
		//because swap is an expensive operation so it is done outside the loop
		swap(a[i], a[min_index]);
	}
	return;
}




int main()  {

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n, key;
	cin>>n;

	int a[1000];

	for(int i=0;i<n;i++) {
		cin>>a[i];
	}

	selection_sort(a,n);

	for(int i=0;i<n;i++) {
		cout<<a[i]<<" ";
	}	

	return 0;
}