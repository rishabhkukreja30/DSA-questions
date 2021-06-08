#include<bits/stdc++.h>
using namespace std;

bool canPlace(int mat[][9], int i, int j, int n, int number) {

	for(int x=0; x<n;x++) {
		//row and column check
		if(mat[x][j] == number || mat[i][x] == number) {
			return false;
		}
	}
	//square grid check
	int rn = sqrt(n);
	int sx = (i/rn)*rn;
	int sy = (j/rn)*rn;

	for(int x =sx; x < sx+rn; x++) {
		for(int y = sy; y < sy +rn; y++) {
			if(mat[x][y] == number) {
				return false;
			}
		}
	}
	return true;
}


bool solveSudoku(int mat[][9], int i, int j, int n) {
	//base case
	if(i==n) {
		//print the matrix
		for(int i=0;i<n;i++) {
			for(int j= 0;j<n;j++) {
				cout<<mat[i][j]<<" ";
			}
			cout<<endl;
		}
		return true;
	}
	//case row end
	if(j==n) {
		return solveSudoku(mat, i+1,0,n);
	}
	//skip the pre-filled cells
	if(mat[i][j] != 0) {
		return solveSudoku(mat, i, j+1, n);
	}
	//rec case
	//fill the current cell with possible options
	for(int number=1;number<=n;number++) {
		if(canPlace(mat, i, j, n, number)) {
			//assume
			mat[i][j] = number;
			bool couldWeSolve = solveSudoku(mat, i, j+1, n);
			if(couldWeSolve == true) {
				return true;
			}
		}
	}
	//Backtrack here
	mat[i][j] = 0;
	return false;
}


int main() {


	// #ifndef ONLINE_JUDGE
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	// #endif

	int mat[9][9] = 
	{
		{5,3,0,0,7,0,0,0,0},
		{6,0,0,1,9,5,0,0,0},
		{0,9,8,0,0,0,0,6,0},
		{8,0,0,0,6,0,0,0,3},
		{4,0,0,8,0,3,0,0,1},
		{7,0,0,0,2,0,0,0,6},
		{0,6,0,0,0,0,2,8,0},
		{0,0,0,4,1,9,0,0,5},
		{0,0,0,0,8,0,0,7,9}
	};

	solveSudoku(mat, 0, 0, 9);

	return 0;
}


	// or
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    
    bool solve(vector<vector<char>>& board){
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == '.'){
                    for(char c = '1'; c <= '9'; c++){
                        if(isValid(board, i, j, c)){
                            board[i][j] = c; 
                            
                            if(solve(board))
                                return true; 
                            else
                                board[i][j] = '.'; 
                        }
                    }
                    
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isValid(vector<vector<char>>& board, int row, int col, char c){
        for(int i = 0; i < 9; i++) {
            if(board[i][col] == c) 
                return false; 
            
            if(board[row][i] == c) 
                return false; 
            
            if(board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) 
                return false; 
        }
        return true;
    }

