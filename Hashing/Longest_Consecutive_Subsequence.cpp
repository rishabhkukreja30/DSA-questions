#include<bits/stdc++.h>
using namespace std;

int longestConsecutiveSubsequence(int *a, int n) {
	unordered_set<int> s;

	for(int i=0;i<n;i++) {
		s.insert(a[i]);
	}
	int ans = 0;
	for(int i=0;i<n;i++) {
		if(s.find(a[i]-1) != s.end()) {
			continue;
		}
		else {
			int count = 0;
			int x = a[i];   // left boundary
			while(s.find(x) != s.end()) {
				count++;
				x++;
			}
			ans = max(ans, count);
		}
	}
	return ans;
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

	int ans = longestConsecutiveSubsequence(arr,n);
	cout<<ans<<endl;

	return 0;

}