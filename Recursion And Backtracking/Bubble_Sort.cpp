#include<bits/stdc++.h>
using namespace std;

//Bubble sort recursively
void bubble_sort(int a[], int n) {
	//base case
	if(n == 1) {
		return;
	}
	//rec case
	//after you have moved the largest element in the current part to the end of the array by pairwise swapping
	for(int j= 0; j<n-1;j++) {
		if(a[j] > a[j+1] ) {
			swap(a[j], a[j+1]);
		}
	}
	//sort the first n-1 elements
	bubble_sort(a, n-1);
}

void bubble_sort_recursive(int a[], int j, int n) {

	//base case
	if(n == 1) {
		return;
	}
	if(j == n-1) {
		//single pass of the current array has been done
		return bubble_sort_recursive(a, 0, n-1);
	}
	//rec case
	if(a[j] > a[j+1]) {
		swap(a[j], a[j+1]);
	}
	bubble_sort_recursive(a, j+1, n);
	return;

}


int main() {

	int a[] = {5,4,3,2,1};
	int n=5;


	return 0;
}