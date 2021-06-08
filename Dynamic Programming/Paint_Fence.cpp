#include<bits/stdc++.h>
using namespace std;

int countWays(int n, int k ) {

	int same = k*1;
	int diff = k * (k-1);
	int total = same + diff;

	for(int i=3;i<=n;i++) {
		same = diff;
		diff = total * (k-1);
		total = same + diff;
	}
	return total;
}


int main() {


	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n, k;
	cin>>n>>k;


	cout<<countWays(n,k)<<endl;


	return 0;
}