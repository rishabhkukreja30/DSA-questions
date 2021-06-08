#include<bits/stdc++.h>
using namespace std;

bool isSafe(int board[][10], int i, int j, int n) {
	//check for column
	for(int row =0;row<i;row++) {
		if(board[row][j] == 1) {
			return false;
		}
	}
	//check for left diagonal
	int x = i;
	int y = j;
	while(x >= 0 && y >= 0) {
		if(board[x][y] == 1) {
			return false;
		}
		x--;
		y--;
	}
	//check for right diagonal
	x = i;
	y = j;
	while(x >= 0 && y < n) {
		if(board[x][y] == 1) {
			return false;
		}
		x--;
		y++;
	}
	//position is now safe
	return true;
}


bool solveNQueen(int board[][10], int i, int n) {
	//base case
	if(i == n) {
		//you have succesfully placed queens in n rows (0....n-1)
		//print the board
		for(int i=0;i<n;i++) {
			for(int j= 0;j<n;j++) {
				if(board[i][j] == 1) {
					cout<<"Q ";
				}
				else {
					cout<<"_ ";
				}
			}
			cout<<endl;
		}
		//return true;

		cout<<endl;
		return false; // to print all possible configurations
	}

	//recursive case
	//Try to place the queen in the current row and call on the remaining part which will be solved by recursion
	for(int j= 0; j<n;j++) {
		//check if i, j th position is safe to place the queen or not
		if(isSafe(board, i, j, n)) {
			//place the queen - assuming i,j is the right position
			board[i][j] = 1;

			bool nextQueenRakhPaye = solveNQueen(board, i+1, n);
			if(nextQueenRakhPaye) {
				return true;
			}
			//i,j is not the right position - assumption is wrong
			board[i][j] = 0;    //Backtrack
		}
	}
	//you have tried for all positions but couldn't place a queen
	return false;
}


int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin>>n;

	int board[10][10] = {0};
	solveNQueen(board, 0, n);



	return 0;
}


// or

    void solve(int col, vector<string> &board, vector<vector<string>> &ans, vector<int> &leftRow, 
               vector<int> &upperDiagonal, vector<int> &lowerDiagonal, int n) {
        if(col == n) {
            ans.push_back(board); 
            return; 
        }
    
        
        for(int row = 0;row<n;row++) {
            if(leftRow[row]==0 && lowerDiagonal[row + col] == 0 
               && upperDiagonal[n-1 + col - row] == 0) {
                
                board[row][col] = 'Q'; 
                leftRow[row] = 1; 
                lowerDiagonal[row+col] = 1; 
                upperDiagonal[n-1 + col - row] = 1;
                solve(col+1, board, ans, leftRow, upperDiagonal, lowerDiagonal, n); 
                board[row][col] = '.'; 
                leftRow[row] = 0; 
                lowerDiagonal[row+col] = 0; 
                upperDiagonal[n-1 + col - row] = 0;
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans; 
        vector<string> board(n);
        string s(n, '.'); 
        for(int i = 0;i<n;i++) {
            board[i] = s; 
        }
        vector<int> leftRow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0); 
        solve(0,board, ans, leftRow, upperDiagonal, lowerDiagonal, n); 
        return ans; 
    }


// or

        bool isSafe1(int row, int col, vector<string> board, int n) {
        // check upper diagonal
        int duprow = row;
        int dupcol = col; 
        
        while(row >= 0 && col >= 0) {
            if(board[row][col] == 'Q') return false;
            row--;
            col--;
        }
        
        
        col = dupcol; 
        row = duprow;
        while(col>=0) {
            if(board[row][col] == 'Q') return false;
            col--; 
        }
    
        row = duprow;
        col = dupcol; 
        while(row<n && col>=0) {
            if(board[row][col] == 'Q') return false;
            row++;
            col--; 
        }
        
        return true; 
    }

    void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n) {
        if(col == n) {
            ans.push_back(board); 
            return; 
        }
    
        for(int row = 0;row<n;row++) {
            if(isSafe1(row, col, board, n)) {
                board[row][col] = 'Q'; 
                solve(col+1, board, ans, n); 
                board[row][col] = '.'; 
            }
        }
    }

    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans; 
        vector<string> board(n);
        string s(n, '.'); 
        for(int i = 0;i<n;i++) {
            board[i] = s; 
        }
         
        solve(0,board, ans, n); 
        return ans; 
    }






    