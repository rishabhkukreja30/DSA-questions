#include<bits/stdc++.h>
using namespace std;

int storeOcc(int *a, int i, int n, int key ,int *out, int j) {
	//base case
	if(i == n) {
		return j;
	}
	if(a[i] == key) {
		out[j] = i;
		//increament j to accomodate current occ
		return storeOcc(a, i+1, n, key ,out, j+1);
	}
	//j remains unchanged
	return storeOcc(a, i+1, n, key, out, j);
}


void allOcc(int *a, int i , int n, int key) {
	if(i==n) {
		return;
	}
	if(a[i] == key) {
		cout<<i<<" ";
	}
	allOcc(a, i+1, n, key);
}


int lastOcc(int *a, int n, int key) {

	if(n == 0 ) {
		return -1;
	}
	//rec case
	int i =lastOcc(a+1, n-1, key);
	if(i == -1) {
		if(a[0] == key) {
			return 0;
		}
		else {
			return -1;
		}
	}
	
	//otherwise if i returned by subproblem is not -1
	return i+1;
}

int firstOcc(int a[], int n, int key) {
	if(n==0) {
		return -1;
	}
	//rec case
	if(a[0] == key) {
		return 0;
	}
	int i =firstOcc(a+1, n-1, key);
	if(i==-1) {
		return -1;
	}
	return i+1;

}

//different style of writing same function (firstOcc)
int linearSearch(int *a, int i, int n, int key) {
	//base case
	if(i == n) {
		return -1;
	}
	//rec  case
	if(a[i] == key) {
		return i;
	}
	return linearSearch(a, i+1, n, key);
}

int main() {

	int arr[] = {1,2,3,7,4,5,6,7,10};
	int key = 7;
	int n = sizeof(arr) / sizeof(int);

	cout<<firstOcc(arr, n ,key)<<endl;
	cout<<lastOcc(arr, n ,key)<<endl;
	allOcc(arr , 0 , n ,key);
	cout<<endl;

	int output[100];
	int cnt = storeOcc(arr, 0, n , key, output , 0);

	cout<<"Count : "<<cnt<<endl;
	for(int k =0;k <cnt; k++) {
		cout<<output[k]<<" ";
	}

	return 0;
}