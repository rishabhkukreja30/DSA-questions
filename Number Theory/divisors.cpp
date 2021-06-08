#include<bits/stdc++.h>
using namespace std;

vector <int> primeSieve(int *p , int n) {

	p[0] = p[1] =0;
	p[2] = 1;

	for(int i=3; i<=n; i+=2) {
		p[i] =1;
	}

	for(int i=3; i<=n; i+=2) {
		if(p[i] == 1) {
			for(int j= i*i; j<=n; j = j+i) {
				p[j] = 0;
			}
		}
	}

	vector <int> primes;
	primes.push_back(2);

	for(int i=3;i<=n;i++) {
		if(p[i] == 1) {
			primes.push_back(i);
		}
	}
	return primes;
}


int no_of_divisors(int m, vector <int> &primes) {

	int i = 0;
	int p = primes[0];
	int ans =1;

	while(p*p <= m )  {
		if(m % p == 0 ) {
			int cnt = 0;
			while( m % p == 0) {
				cnt++;
				m = m/p;
			}
			ans = ans * (cnt +1);
		}
		//go to the next position
		i++;
		p = primes[i] ;

	}

	if( m != 1) {
		ans = ans * 2;
	}

	return ans;

}

int main() { 


	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n =100;
	int p[n];
	for(int i=0; i<=n;i++) {
		p[i] = 0;
	}
	vector <int > primes = primeSieve(p,100);

	int t;
	cin>>t;

	while(t--) {
		int no;
		cin>>no;

		int divis = no_of_divisors(no, primes);
		cout<<divis<<endl;
	}
	
	return 0;
}

