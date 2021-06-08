#include<bits/stdc++.h>
using namespace std;

int longestSubarrayWithSum0(int *a, int n) {
	unordered_map <int , int> m;
	int pre = 0;
	int len = 0;
	for(int i=0;i<n;i++) {
		pre += a[i];
		if(a[i] ==0 and len ==0 ) {
			len = 1;
		}
		if(pre ==0) {
			len = max(len, i+1);
		}
		if(m.find(pre) != m.end()) {
			len = max(len, i - m[pre]);
		}
		else {
			m[pre] = i;
		}
	}
	return len;
}


int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin>>n;
	int *arr = new int[n];
	for(int i=0;i<n;i++) {
		cin>>arr[i];
	}

	int b = longestSubarrayWithSum0(arr,n);
	cout<<b<<endl;

	return 0;

}