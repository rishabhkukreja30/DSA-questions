#include<bits/stdc++.h>
using namespace std;



int main() {
	int n;
	cin>>n;
	int a[n][n];
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			cin>>a[i][j];
		}
	}

	
	for(int i=0;i<n;i++) {
		// find least in row
		int smallest_value_j = 0;
		for(int j=1;j<n;j++) {
			if(a[i][j] < a[i][smallest_value_j]) {
				smallest_value_j = j;
			}
		}

		// check if it is max in column
		bool flag = true;
		for(int k=0;k<n;k++) {
			if(a[k][smallest_value_j] > a[i][smallest_value_j]) {
				flag = false;
				break;
			}
		}

		if(flag == true) {
			cout<<a[i][smallest_value_j];
		}
		else {
			cout<<"-1";
		}
	}



	return 0;
}