#include<bits/stdc++.h>
using namespace std;

char words[][10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};

void printSpellings(int n) {
	//base case
	if(n == 0) {
		return;
	}

	//rec case - first print spellings of 204
	printSpellings(n/10);
	int digit = n % 10;
	cout<<words[digit]<<" ";
	return;
}


int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n; 
	cin>>n;

	printSpellings(n);

	return 0;
}