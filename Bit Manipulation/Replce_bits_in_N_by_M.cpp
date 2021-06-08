#include<bits/stdc++.h>
using namespace std;

int clearRangeItoJ(int n, int i, int j) {
	int ones = (~0);
	int a = ones<<(j+1);
	int b = (1 <<i)-1;
	int mask = a|b;
	int ans = (n & mask);
	return ans;
}


int replaceBits(int n, int m, int i, int j) {
	int n_ = clearRangeItoJ(n,i,j);
	int ans  = n_ | (m << i);
	return ans;
}



int main() {


	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	int n=15, m =2, i= 1, j =3;

	cout<<replaceBits(n , m,i, j)<<endl;

	return 0;
}