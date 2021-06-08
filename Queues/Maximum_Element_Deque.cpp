#include<iostream>
#include<deque>
using namespace std;



int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	int a[100000];
	int k;

	cin>>n;
	for(int i=0;i<n;i++) {
		cin>>a[i];
	}

	cin>>k;

	//we have to process first k elements separately
	deque <int> q;
	int i;

	for( i=0;i<k;i++) {

		while(!q.empty() && a[i] > a[q.back()]) {
			q.pop_back();
		}
		q.push_back(i);
	}
	//process the remaining elements
	for(;i<n;i++) {
		cout<<a[q.front()]<<" ";

		//1. remove the elements which are not part of the window (contraction)
		while(!q.empty() && (q.front() <= i-k)) {
			q.pop_front();
		}

		//2. remove the elements which are not useful and are in the window
		while(!q.empty() && a[i] >= a[q.back()]) {
			q.pop_back();
		}

		//3. add the new elements (expansion)
		q.push_back(i);

	}
	cout<<a[q.front()];

	return 0;
}
