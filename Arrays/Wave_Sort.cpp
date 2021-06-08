#include<bits/stdc++.h>
using namespace std;


void wave_sort(int a[], int n) {
	//sort the array in wave form
	for(int i=0;i<n;i+=2) {

		//prev element
		if(i != 0 and a[i] < a[i-1]) {
			swap(a[i], a[i-1]);
		}
		//next element
		if(i != (n-1) and a[i] <a[i+1]) {
			swap(a[i], a[i+1]);
		}
	}
	return;
}

int main()   {

	int a[] = {1,3,4,2,7,8};
	int n = sizeof(a)/sizeof(int);

	wave_sort(a,n);

	for(int i=0;i<n;i++) {
		cout<<a[i]<<" ";
	}




	return 0;
}