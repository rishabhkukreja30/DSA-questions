#include<bits/stdc++.h>
using namespace std;


int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	char a[100][100];

	//read a list of strings and store them in a character 2d array
	int n;
	cin>>n;

	cin.get();
	for(int i=0;i<n;i++) {
		cin.getline(a[i], 100);

	}

	for(int i=0;i<n;i++) {
		cout<<a[i]<<endl;
	}

	return 0;
}