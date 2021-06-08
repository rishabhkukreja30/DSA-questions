#include<bits/stdc++.h>
using namespace std;

bool isOdd(int n) {
	return ( n & 1 );
}

int getBit(int n ,int i) {
	int mask = (1 << i);
	int bit = (n & mask) > 0 ? 1 : 0;
	return bit;
}

int setBit(int n, int i) {
	int mask = (1 << i);
	int ans = n|mask;
	return ans;
}

void clearBit(int &n, int i) {
	int mask = ~(1 << i);
	n = (n & mask);
}

void updateBit(int &n ,int i, int v) {
	int mask = ~(1 << i);
	int cleared_n = n & mask;
	n = cleared_n|(v << i);
}

int clearLastIBits(int n, int i) {
	int mask = (-1 << i);
	return n & mask;
}

int clearRangeItoJ(int n, int i, int j) {
	int ones = (~0);
	int a = ones<<(j+1);
	int b = (1 <<i)-1;
	int mask = a|b;
	int ans = (n & mask);
	return ans;
}

int main() {


	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n =5;
	int i;
	cin>>i;

	cout<<getBit(n, i)<<endl;
	cout<<setBit(n, i)<<endl;

	clearBit(n, i);
	cout<<n<<endl;

	updateBit(n,2,0);
	updateBit(n, 3,1);
	cout<<n<<endl;

	// from position i+1 to 0
	cout<<clearLastIBits(15, 3)<<endl;
	cout<<clearRangeItoJ(31, 1, 3)<<endl;

	return 0;
}