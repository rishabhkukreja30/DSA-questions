#include<bits/stdc++.h>
using namespace std;


void DNF_Sort(int a[], int n) {
	//sort array of 0s , 1s and 2s
	int low = 0;
	int mid = 0;
	int high = n-1;

	while(mid<=high) {

		if(a[mid] == 0) {
			swap(a[mid], a[low]);
			low++;
			mid++;
		}
		else if(a[mid] == 1) {
			mid++;
		}
		else if(a[mid] == 2) {
			swap(a[mid], a[high]);
			high--;                   // not doing mid++ bcoz there may be a case if swapped element is 0 and we again 
		}							  // need to check the first case							
	}
	return;
}


int main()   {

	int a[] = {2,1,1,1,1,0,1,1,1,0,0,2,0};
	int n = sizeof(a)/sizeof(int);

	DNF_Sort(a,n);
	for(int i=0;i<n;i++) {
		cout<<a[i]<<" ";
	}

	return 0;
}