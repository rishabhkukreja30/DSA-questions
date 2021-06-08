#include<bits/stdc++.h>
using namespace std;

void permute(char *in, int i) {
	//base case
	if(in[i] == '\0') {
		cout<<in<<" ";
		return;
	}
	//recursive case
	for(int j = i; in[j] != '\0'; j++) {
		swap(in[i], in[j]);
		permute(in, i+1);
		//Backtracking - To restore the orginal array
		swap(in[i], in[j]);
	}
	return;
}

int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	char in[100];
	cin>>in;

	permute(in, 0);



	return 0;
}