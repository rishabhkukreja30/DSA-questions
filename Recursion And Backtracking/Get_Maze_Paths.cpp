#include<bits/stdc++.h>
using namespace std;

void printMazePaths(int sr, int sc, int dr, int dc, string psf) {
	if(sr >dr || sc > dc) {
		return;
	}
	if(sr == dr and sc == dc) {
		cout<<psf<<endl;
		return;
	}
	printMazePaths(sr, sc+1, dr,dc, psf + "h");
	printMazePaths(sr+1,sc, dr, dc, psf+ "v");

}

void printMazePathsWithJumps(int sr, int sc, int dr, int dc, string psf) {
	if(sr = dr and sc == dc) {
		cout<<psf<<endl;
		return;
	}
	for(int ms =1; ms <= dc- sc;ms++) {
		printMazePathsWithJumps(sr ,sc +ms, dr,dc,psf+"h"+ ms );
	}
	for(int ms =1; ms <= dr- sr; ms++) {
		printMazePathsWithJumps(sr +ms,sc, dr,dc,psf+"v"+ ms );
	}
	for(int ms =1; ms <= dr -sr and ms <= dc- sc;ms++) {
		printMazePathsWithJumps(sr +ms ,sc +ms, dr,dc,psf+"d"+ ms );
	}
}



int main() {

	int n, m;
	cin>>n>>m;

	printMazePaths(1,1,n,m,""); 

	return 0;
}