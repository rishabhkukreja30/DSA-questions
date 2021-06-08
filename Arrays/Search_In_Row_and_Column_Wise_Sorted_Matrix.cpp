#include<bits/stdc++.h>
using namespace std;

// gfg ques soln
int i = 0, j = m-1;
while(i < n and j>= 0) {
	if(mat[i][j] == x) {
		return  true;
	}

	if(mat[i][j] > x) {
		j--;
	}
	else {
		i++;
	}
}


// leetcode ques soln - O(log(n*m))
bool searchMatrix(vector <vector <int> > &matrix, int target) {
	if(matrix.size() == 0) {
		return false;
	}

	int n = matrix.size();
	int m = matrix[0].size();

	int lo = 0, hi =(n*m)-1;

	while(lo <= hi) {
		int mid = (lo+ (hi-lo)/2);

		if(matrix[mid/m][mid%m] == target) {
			return true;
		}
		if(matrix[mid/m][mid%m] < target) {
			lo = mid+1;
		}
		else {
			hi = mid-1;
		}
	}
	return false;
}







