#include<bits/stdc++.h>
using namespace std;

// O(n^3)

int main()  {

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin>>n;

	int a[1000];
	int max_sum = 0;
	int curr_sum = 0;
	int left = -1;
	int right = -1;


	for(int i=0;i<n;i++) {
		cin>>a[i];
	}

	//generate all subarrays
	for(int i=0;i<n;i++) {
		for(int j=i;j<n;j++) {
			//elements of subarray(i,j)
			curr_sum = 0;
			for(int k=i;k<=j;k++) {
				curr_sum += a[k];
			}
			// update max_sum if curr_sum > max_sum
			if(curr_sum > max_sum) {
				max_sum = curr_sum;
				left = i;
				right = j;
			}
		}
	}
	cout<<max_sum<<endl;

	// print the subarray
	for(int k = left; k<=right;k++) {
		cout<<a[k]<<" ";
	}
	return 0;
}