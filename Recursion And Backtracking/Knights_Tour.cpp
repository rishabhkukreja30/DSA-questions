#include<bits/stdc++.h>
using namespace std;

void KnightsTour(int board[][10] , int r ,int c,int n, int move) {
	if(r <0 || c <0 || r >= n || c >= n || board[r][c] > 0 ) {
		return;
	}
	else if(move == n*n) {
		board[r][c] = move;
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				cout<<board[i][j]<<" ";
			}
			cout<<endl;
		}
		board[r][c] = 0;
		return;
	}


	board[r][c] = move;
	KnightsTour(board, r-2, c+1, n, move+1);
	KnightsTour(board, r-1, c+2, n, move+1);
	KnightsTour(board, r+1, c+2, n, move+1);
	KnightsTour(board, r+2, c+1, n, move+1);
	KnightsTour(board, r+2, c-1, n, move+1);
	KnightsTour(board, r+1, c-2, n, move+1);
	KnightsTour(board, r-1, c-2, n, move+1);
	KnightsTour(board, r-2, c-1, n, move+1);
	board[r][c] = 0;
}


int main() {

	int n ,r, c;
	cin>>n>>r>>c;

	int board[10][10] = {0};

	KnightsTour(board, r,c,n, 1);


	return 0;
}