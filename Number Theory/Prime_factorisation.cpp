#include<bits/stdc++.h>
using namespace std;

void printFactors(int n) {

	vector <pair<int ,int> > factors;
	int cnt;

	for(int i=2; i*i <= n; i++) {

		if(n % i == 0) {
			//keep on dividing it by i if it is divisible
			cnt =0;
			while(n % i == 0) {
				cnt++;
				n = n/i;
			}
			factors.push_back(make_pair(i,cnt));
		}
	} 
	if(n != 1) {
		//whatever is left is a prime number in itself
		factors.push_back(make_pair(n, 1));
	}
	
	//print the factors
	for(auto p : factors) {
		cout<<p.first<<"^"<<p.second<<endl;
	}

	 return;
}



int main() {


	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin>>n;

	printFactors(n);

	return 0;
}