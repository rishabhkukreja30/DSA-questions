#include<bits/stdc++.h>
using namespace std;


int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin>>n;

	int a[1000];
	int current_sum = 0;
	int max_sum = 0;
	
	for(int i=0;i<n;i++) {
		cin>>a[i];
	}

	//kadane's algorithm for maximum sum subarray
	for(int i=0;i<n;i++) {
		current_sum = current_sum  + a[i];
		
		max_sum = max(current_sum, max_sum);

		if(current_sum < 0 ) {
			current_sum  =0;
		}
		
	}

	cout<<"Maximum sum is "<<max_sum<<endl;


	return 0;

}
