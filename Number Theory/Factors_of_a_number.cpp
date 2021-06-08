#include<bits/stdc++.h>
using namespace std;


#define ll long long 
#define mod = 1e9 +7 // 10^9 + 7

vector <int> fact(n) {

	vector<int> v;

	for(int i=1;i*i<=n;i++) {
		if(n%i==0) {
			v.push_back(i);
			if(i != n/i) {
				v.push_back(n/i);
			}
		}
	}
	return v;

}



// to  check whether a number is prime or not (for numbers greater than 10^7)
bool isprime(int n) {
	if(n<=1e6) {
		return isprime[n];	
	}
	for(auto i :primes) {
			if(i > sqrt(n)) {
				return true;
			}
			if(n % i == 0) {
				return false;
			}
	}
	return true;

}

// totient function - O(sqrt(n)/ log(sqrt(n))) - can work upto integer of order 10^12
ll int eulerPhi(ll int n) {
	ll pf_idx = 0, pf = primes[pf_idx];
	ll ans = n;

	while(pf*pf <= n) {
		if(n % pf == 0) {
			ans -= ans/pf;
		}
		while(n%pf == 0) {
			n /= pf;
		}
		pf = primes[++pf_idx];
	}
	if(n != -1) {
		ans -= ans /n;
	}
	return ans;
}

// modulo arithmetic
vector <ll int> fact(1e6, 1);

ll int factorial( int n) {
	for(int i=2;i<=n;i++) {
		fact[i] = (fact[i-1] * i)%mod;
	}
	return fact[n]%mod;
}


// extended euclid algorithm
int x, y, d;
void extended_euclid(int a, int b) {
	if( b== 0) {
		x =1;
		y =0;
		d =a;
		return ;
	}
	extended_euclid(b, a%b);   // same as gcd
	int x1 = y;
	int y1 = x - (a/b) * y;
	x = x1;
	y = y1;
}

// OR
int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

// diophantine equation
bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}

/*

From one solution (x0,y0), we can obtain all the solutions of the given equation.

Let g=gcd(a,b) and let x0,y0 be integers which satisfy the following:

a⋅x0+b⋅y0=c
Now, we should see that adding b/g to x0, and, at the same time subtracting a/g from y0 will not break the equality:

a⋅(x0+bg)+b⋅(y0−ag)=a⋅x0+b⋅y0+a⋅bg−b⋅ag=c
Obviously, this process can be repeated again, so all the numbers of the form:

x=x0+k⋅bg
y=y0−k⋅ag
are solutions of the given Diophantine equation.

Moreover, this is the set of all possible solutions of the given Diophantine equation. */
