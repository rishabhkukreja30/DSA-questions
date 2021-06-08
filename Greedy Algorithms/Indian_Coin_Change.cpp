#include<bits/stdc++.h>
using namespace std;

int make_change(int *coins, int n, int money) {

	int ans = 0;

	while(money >0) {
		int idx = upper_bound(coins, coins +n , money) -1 - coins;
		cout<<coins[idx]<<" + ";
		money = money - coins[idx];
		ans++;
	}
	return ans;
}


int main() {


	#ifndef ONLINE_JUDGEs
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int money;
	cin>>money;

	int coins[] = {1,2,5,10,20,50,100,200,500,2000};
	int t = sizeof(coins) /sizeof(int);

	cout<<"Coins needed = "<<make_change(coins, t, money);



	return 0;
}


// or 

void find(int v) {

	int denom[] = {1,2,5,10,20,50,100,500,1000};
	int n = 9;

	vector <int> ans;

	for(int i=n-1;i>=0;i--) {

		while( v >= denom[i]) {
			v-= denom[i];
			ans.push_back(denom[i]);
		}
	}
}