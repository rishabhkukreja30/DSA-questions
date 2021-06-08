#include<bits/stdc++.h>
using namespace std;

void spiral_print(int a[][10], int m, int n) {

	int startRow = 0;
	int startCol = 0;
	int endRow = m-1;
	int endCol = n-1;

	while(startRow <= endRow and startCol <= endCol) {
		// first row
		for(int i=startCol; i<= endCol; i++) {
			cout<<a[startRow][i]<<" ";
		}
		startRow++;

		for(int i = startRow; i<= endRow;i++) {
			cout<<a[i][endCol]<<" " ;
		}
		endCol--;

		//bottom row
		if(endRow >startRow) {
			for(int i=endCol; i>= startCol; i--) {
				cout<<a[endRow][i]<<" ";
			}
		endRow--;
		}

		//start col
		if(startCol >endCol) {
			for(int i=endRow;i>=startRow;i--) {
				cout<<a[i][startCol]<<" ";
			}
		startCol++;	
		}

	}

}

// or
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty()) {
            return {};
        }
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<int>ans;

        
        int startRow = 0;
        int startCol = 0;
        int endRow = m;
        int endCol = n;
        
        
        
        while(startRow < endRow and startCol < endCol) {
            
            for(int i=startCol;i<endCol;i++) {
                ans.push_back(matrix[startRow][i]);
            }
            startRow++;
            
            for(int j=startRow;j<endRow;j++) {
                ans.push_back(matrix[j][endCol-1]);
            }
            endCol--;
            
            if(startRow <endRow) {
                for(int i=endCol-1;i>=startCol;i--) {
                    ans.push_back(matrix[endRow-1][i]);
                }
                endRow--;
            }
            
            
            if(endCol >startCol) {
                for(int j=endRow-1;j>=startRow;j--) {
                    ans.push_back(matrix[j][startCol]);
                }
                startCol++;
            }
            
        }
        return ans;
    }



int main() {
	

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	
	int a[10][10] = {0};	
	int m,n;
	cin>>m>>n;

	int val = 1;

	for(int row =0;row<m;row++) {
		for(int col=0;col<n;col++) {
			a[row][col]  =val;
			val = val  +1;
			cout<<a[row][col] <<" ";
		}
		cout<<endl;
	}


	//wave print
	for(int col=0;col<n;col++) {

		if(col % 2 ==0) {
			// even col - top down
			for(int row =0;row<m;row++) {
				cout<<a[row][col]<<" ";
			}
		}
		else {
			//bottom up direction
			for(int row = m-1;row>=0;row--) {
				cout<<a[row][col]<<" ";
			}
		}

	}
	cout<<endl;

	spiral_print(a,m,n);


	return 0;

}

