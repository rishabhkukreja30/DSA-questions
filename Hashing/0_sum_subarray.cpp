#include<bits/stdc++.h>
using namespace std;

bool checkSubarrayWith0Sum(int *a, int n) {
	unordered_set <int> s;
	int pre = 0;
	for(int i=0;i<n;i++) {
		pre += a[i];
		if(pre == 0 or s.find(pre) != s.end()) {
			return true;
		}
		s.insert(pre);
	}
	return false;
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

	bool b  = checkSubarrayWith0Sum(arr, n);
	if(b) {
		cout<<"Yes"<<endl;
	}
	else {
		cout<<"No"<<endl;
	}

	return 0;
}
