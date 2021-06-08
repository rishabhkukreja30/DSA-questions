#include<bits/stdc++.h>
using namespace std;

#define ll long long

//naive approach O(sqrt(n))
bool isPrime(int n) {
	if(n==1) {
		return false;
	}
	if(n==2) {
		return true;
	}
	for(int i=2; i*i < n ; i++) {
		if(n % i == 0) {
			return false;
		}
	}
	return true;
}

//Sieve Approach - Generate an array containing prime numbers
void prime_sieve(int *p) {
	//first mark all odd numbers as prime
	for(int i=3;i<=100000;i+=2)  {
		p[i] =1;
	}

	//Sieve
	for(ll i=3;i<=100000;i+=2) {
		//if the current number is not marked (it is prime)
		if(p[i]==1) {
			//mark all multiples of i as not prime
			for(ll j = i*i; j<=100000; j = j+ i) {
				p[j] =0 ;
			}
		}
	}

	//special cases
	p[2] =1;
	p[1] = p[0] = 0;

}



int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin>>n;
	int p[100005] =  {0};
	prime_sieve(p);

	//print all primes upto range n
	for(int i=0; i<=n; i++) {
		if(p[i] == 1) {
			cout<<i<<" ";
		}
	}

	return 0;
}
