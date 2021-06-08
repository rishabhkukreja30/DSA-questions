#include<bits/stdc++.h>
using namespace std;

int power_optimised(int a, int n) {
	int ans = 1;

	while(n > 0) {
		int last_bit = (n&1);
		if(last_bit) {
			ans = ans * a;
		}
		a = a * a;  // square up
		n = n>>1;     // discard the last bit of n
	}
	return ans;
}


int main() {


	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int a, n;
	cin>>a>>n;

	cout<<power_optimised(a, n)<<endl;



	return 0;
}