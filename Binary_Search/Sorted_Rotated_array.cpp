#include<bits/stdc++.h>
using namespace std;

int find(int a[], int n, int key) {
	int s=0, e =n-1;
	while(s<=e) {
		int mid = (s+e) /2;
		if(a[mid] == key) {
			return mid;
		}
		else if(a[s] <= a[mid]) {
			//2 cases - element lies on the left or right of the mid
			if(key >= a[s] and key <= a[mid]) {
				e = mid -1;
			}
			else {
				s = mid +1;
			}
		}
		else {
			if(key >= a[mid] and key <= a[e]) {
				s =mid +1;
			}
			else {
				e= mid -1;
			}
		}
	}
	return -1;
}


int main()  {


	#ifndef ONLINE_JUDGEs
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin>>n;
	int a[100000];
	for(int i=0;i<n;i++) {
		cin>>a[i];
	}

	int key;
	cin>>key;

	cout<<find(a,n,key);



	return 0;
}