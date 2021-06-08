#include<bits/stdc++.h>
using namespace std;

void rotate(int a[][100], int n) {

	//reverse each row
	for(int row=0;row<n;row++) {
		int start_col =0;
		int end_col = n-1;
		while(start_col <end_col) {
			swap(a[row][start_col], a[row][end_col]);
			start_col++;
			end_col--;
		}
	}
	//to take transpose
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			if(i<j) {
				swap(a[i][j], a[j][i]);
			}
		}
	}

}



void rotate_STL(int a[][100], int n) {

	//reverse each row
	for(int i=0;i<n;i++) {
		reverse(a[i] , a[i]+n);
	}

	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			if(i<j) {
				swap(a[i][j], a[j][i]);
			}
		}
	}
}


int main() {
	

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin>>n;

	int a[100][100];

	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			cin>>a[i][j];
		}
	}

	rotate(a,n);

	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}

	rotate_STL(a,n);
	
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}



	return 0;
}