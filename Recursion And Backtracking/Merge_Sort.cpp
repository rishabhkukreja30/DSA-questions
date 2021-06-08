#include<bits/stdc++.h>
using namespace std;

void merge(int *a, int s, int e) {
	int mid = (s + e) /2;
	int i= s , j = mid+1 , k =s;
	int temp[100];

	while(i <= mid && j <= e) {
		if(a[i] < a[j]) {
			temp[k++] = a[i++];
		}
		else {
			temp[k++] = a[j++];
		}
	}
	while(i <= mid) {
		temp[k++] = a[i++];
	}
	while(j <= e) {
		temp[k++] = a[j++];
	}
	//copy all elemnts to the orginal array
	for(int i=s;i<=e;i++) {
		a[i] = temp[i];
	}
}


void merge_sort(int a[], int s, int e) {

	//base case - 1 or 0 elements 
	if(s>=e) {
		return;
	}

	//follow 3 steps
	//1. Divide
	int mid = (s + e) /2;
	//recursuvely the arrays
	merge_sort(a, s, mid);
	merge_sort(a, mid+1, e);

	//merge the two parts
	merge(a ,s, e);

}


int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int a[100];
	int n;
	cin>>n;

	for(int i=0;i<n;i++) {
		cin>>a[i];
	}

	merge_sort(a, 0, n-1);

	for(int i=0;i<n;i++) {
		cout<<a[i]<<" ";
	}


	return 0;
}