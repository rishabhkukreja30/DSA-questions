#include<bits/stdc++.h>
using namespace std;


int findPltforms (int arr[], int dep[], int n) {

	sort(arr,arr+n);
	sort(dep, dep+n);

	int platfroms_needed = 1;
	int result = 1;

	int i=1, j=0;

	while(i <n and j < n ) {
		if(arr[i] <= dep[j]) {
			platfroms_needed++;
			i++;
		}
		else if(arr[i]  >dep[j]) {
			platfroms_needed--;
			j++;
		}

		if(platfroms_needed > result) {
			result = platfroms_needed;
		}
	}
	return result;
}