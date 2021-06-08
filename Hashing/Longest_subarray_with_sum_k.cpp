#include<bits/stdc++.h>
using namespace std;

int longestSubarrayWithSumK(int *a, int n, int k) {
	 unordered_map <int , int> m;
	int pre = 0;
	int len = 0;
	for(int i=0;i<n;i++) {
		pre += a[i];

		if(pre == k) {
			len = max(len, i+1);
		}
		if(m.find(pre) == m.end()) {
		    m[pre] = i;
		}
		if(m.find(pre - k) != m.end()) {
			len = max(len , i-m[pre-k]);
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
	int k;
	cin>>k;

	int b = longestSubarrayWithSumK(arr,n, k);
	cout<<b<<endl;

	return 0;

}