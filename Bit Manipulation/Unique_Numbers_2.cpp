#include<bits/stdc++.h>
using namespace std;




int main() {


	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	int a[1000005];
	cin>>n;

	int no;
	int res = 0;
	for(int i=0;i<n;i++) {
		cin>>no;
		a[i] = no;
		res = res^no;
	}

	//res = a^b
	int temp = res;
	int pos = 0;
	while((temp&1) != 1) {
		pos++;
		temp = temp>>1;
	}

	// the first set bit in xor is at position 'pos'
	int mask = (1 << pos);

	// find those numbers which contain set bit at position pos
	int x = 0;
	int y = 0;
	
	for(int i=0;i<n;i++) {
		if((a[i] & mask) > 0) {
			x = x^a[i];
		}
	}
	y = res^x;

	cout<<min(x,y)<<" "<<max(x,y)<<endl;

	return 0;
}