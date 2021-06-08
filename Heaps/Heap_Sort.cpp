#include<bits/stdc++.h>
using namespace std;

void print(vector <int> v) {
	for(int i=1;i<v.size(); i++) {
		cout<<v[i]<<" ";
	}
	cout<<endl;
}


bool minHeap = false;

bool compare(int a, int b) {
	if(minHeap) {
		return a < b;
	}
	else {
		return a > b;
	}
}

void heapify(vector<int> &v, int idx, int size) {
	int left = 2 * idx;
	int right = left + 1;

    int min_idx = idx;
	int last = size - 1;

	if(left <= last && compare(v[left], v[idx])) {
		min_idx = left;
	}
	if(right <= last && compare(v[right], v[min_idx])) {
		min_idx = right;
	}

	if(min_idx != idx) {
		swap(v[idx], v[min_idx]);
		heapify(v, min_idx, size);
	}
}

// O(n)
void buildHeapOptimized(vector <int> &v) {
	for(int i=(v.size() -1) /2; i>=1;i--) {
		heapify(v, i, v.size());
	}
}

void heapsort(vector<int> &arr) {

	buildHeapOptimized(arr);
	int n = arr.size();

	//remove n-1 elements from the heap
	while(n>1) {
		swap(arr[1], arr[n-1]);
		//remove that element from the heap
		n--;
		heapify(arr, 1, n);
	}
}


int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	vector <int> v;
	v.push_back(-1);

	int n;
	cin>>n;

	int temp;
	for(int i=0;i<n;i++) {
		cin>>temp;
		v.push_back(temp);
	}

	heapsort(v);
	print(v);

	return 0;
}








