#include<bits/stdc++.h>
using namespace std;

// right to left -  to maintain array order
void nextGreaterElement(int a[], int n) {
	int ans[n];

	stack <int> s;
	s.push(a[n-1]);
	ans[n-1] = -1;

	for(int i=n-2;i>=0;i--) {
		while(!s.empty() and a[i] > s.top() ) {
			s.pop();
		}

		if(s.empty()) {
			ans[i] = -1;
		}
		else {
			ans[i] = s.top();
		}
		s.push(a[i]);
	}
	for(int i=0;i<n;i++) {
		cout<<ans[i]<<" ";
	}
}

//left to right
void nextGreaterElement2(int a[], int n) {
	int ans[n];
	stack <int> s;
	s.push(0);

	for(int i=1;i<n;i++) {
		while(!s.empty() && a[i] > a[s.top()]) {
			int x = s.top();
			ans[x] = a[i];
			s.pop();
		}
		s.push(i);
	}
	while(!s.empty()) {
		int x = s.top();
		s.pop();
		ans[x] = -1;
	}
	for(int i=0;i<n;i++) {
		cout<<ans[i]<<" " ;
	}
}

int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++) {
		cin>>a[i];
	}

	nextGreaterElement(a,n);
	cout<<endl;
	nextGreaterElement2(a,n);

	return 0;
}