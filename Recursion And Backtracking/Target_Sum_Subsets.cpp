#include<bits/stdc++.h>
using namespace std;


void targetSumSubsets(int a[], int i, int n, string set, int sum, int target) {
	if(i == n) {
		if(sum == target) {
			cout<<set<<endl;
		}
		return;
	}
	targetSumSubsets(a, i+1, set + a[i] + " ",sum + a[i], target);
	targetSumSubsets(a, i+1, set,sum, target);
}






int main() {


	int n;
	cin>>n;
	int a[n];

	for(int i=0;i<n;i++) {
		cin>>a[i];
	}
	int target;
	cin>>target;
	string s  = "";

	targetSumSubsets(a,0,n,s,0,target);

	return 0;
}