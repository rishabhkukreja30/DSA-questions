#include<bits/stdc++.h>
using namespace std;

int first_occurence(int a[], int n, int key) {
	int s=0, e =n-1;

	int ans = -1;
	//update in a direction that ans value gets lower and lower
	while(s<=e) {
		int mid = (s+e) /2;
		if(a[mid] == key) {
			ans = mid;
			e = mid-1;
		}
		else if(a[mid] > key) {
			e = mid -1;
		}
		else {
			s = mid+ 1;
		}
	}
	return ans;
}


int last_occurence(int a[], int n, int key) {
	int s=0, e =n-1;

	int ans = -1;
	//update in a direction that ans value gets higher and higher
	while(s<=e) {
		int mid = (s+e) /2;
		if(a[mid] == key) {
			ans = mid;
			s = mid+1;
		}
		else if(a[mid] > key) {
			e = mid -1;
		}
		else {
			s = mid+ 1;
		}
	}
	return ans;
}



int main() {

	#ifndef ONLINE_JUDGEs
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int arr[] = {1,2,5,8,8,8,8,8,10,12,15,20};
	int n = sizeof(arr) / sizeof(int);

	int key;
	cin>>key;

	cout<<first_occurence(arr,n,key)<<endl;
	cout<<last_occurence(arr,n,key)<<endl;

	return 0;
}