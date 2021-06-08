#include<bits/stdc++.h>
using namespace std;


bool isPossible(int a[], int n, int m, int current_min) {
	int studentUsed = 1;
	int pages_reading = 0;

	for(int i=0;i<n;i++) {

		if(pages_reading + a[i] > current_min) {
			studentUsed++;

			pages_reading = a[i];
			if(studentUsed  >m) {
				return false;
			}
		}
		else {
			pages_reading += a[i];
		}
	}
	return true;
}


int findPages(int a[], int n, int m) {
	int sum = 0;

	if(n<m) {
		return -1;
	}

	// count the number of pages
	for(int i=0;i<n;i++) {
		sum += a[i];
	}

	int s = a[n-1];
	int e = sum;
	int ans = INT_MAX;

	while(s<=e) {
		int mid = (s+e)/2;

		if(isPossible(a,n,m,mid)) {
			ans = min(ans, mid);
			e = mid -1;
		}
		else {
			// it is not possible to divide x pages
			// increase the no. of pages
			s = mid + 1;
		}
	}
	return ans;
}


int main()  {


	#ifndef ONLINE_JUDGEs
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int t;
	cin>>t;

	while(t--) {
		int n,m;
		cin>>n>>m;

		int arr[1000];
		for(int i=0;i<n;i++) {
			cin>>arr[i];
		}

		cout<<findPages(arr,n,m)<<endl;
	}

	return 0;
}