#include<bits/stdc++.h>
using namespace std;




int main() {


	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int cnt[64] = {0};
	int n, no;
	cin>>n;

	for(int i=0;i<n;i++) {
		cin>>no;
		// update the cnt array by extracting bits
		int j = 0;
		while(no > 0) {
			int last_bit = (no&1);
			cnt[j] += last_bit;
			j++;
			no = no>>1;
		}
	}

	//iterate over the array and form the answer by converting 0s and 1s into  a number
	int p = 1;
	int ans = 0;
	for(int i=0;i<64;i++) {
		cnt[i] %= 3;
		ans += (cnt[i]*p);
		p = p<<1;
	}

	cout<<ans<<endl;

	return 0; 
}
