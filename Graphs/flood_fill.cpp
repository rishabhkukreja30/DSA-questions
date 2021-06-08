#include<bits/stdc++.h>
using namespace std;

// W N E S
int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};


//ch is the character to be replaced 
// color is the character to be added

int R, C;

void floodFill(char mat[][50], int i, int j, char ch, char color) {

	//base case: matrix bounds
	if(i<0 || j<0 || i>=R || j>=C) {
		return;
	}

	//figure boundary condition
	if(mat[i][j] != ch)
		return;

	//recursive call
	mat[i][j] = color;

	// printMatrix(mat);
	// cout<<endl;

	for(int k=0;k<4;k++){
		floodFill(mat, i+dx[k], j+dy[k], ch, color);
	}

}


void printMatrix(char input[][50]) {

	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			cout<<input[i][j];
		}
		cout<<endl;
	}
}

int main() {

	
	cin>>R>>C;

	char input[15][50];

	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			cin>>input[i][j];
		}
	}

	printMatrix(input);

	floodFill(input, 8, 13, '.', 'r');

	printMatrix(input);

	return 0;
} 