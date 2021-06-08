#include <bits/stdc++.h>
using namespace std;

#define ll long long int

// recursive soln

ll coins[40];

ll optimalGame(ll i,ll j){
    if(i > j){
        return 0;
    }

    // Consider both the possibilities. You can pick either the first or the last coin.
    // Since the opponent plays optimally , we would get the minimum of the remaining coins for each choice.
    ll pickFirst = coins[i] + min( optimalGame(i+2,j) , optimalGame(i+1,j-1) ) ;
    ll pickLast = coins[j] + min( optimalGame(i,j-2) , optimalGame(i+1,j-1) ) ;

    // Pick the max of two as your final result
    ll ans = max(pickFirst,pickLast);

    return ans;
}

// dp soln
ll coins[10005];
ll dp[5000][5000];

ll optimalGame(ll i,ll j){
    if(i > j){
        return 0;
    }
    if(i<5000 && j<5000){
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
    }

    ll pickFirst = coins[i] + min( optimalGame(i+2,j) , optimalGame(i+1,j-1) ) ;
    ll pickLast = coins[j] + min( optimalGame(i,j-2) , optimalGame(i+1,j-1) ) ;

    ll ans = max(pickFirst,pickLast);

    if(i<5000 && j<5000){
        dp[i][j] = ans ; 
    }

    return ans;
}




int main() {
    int n;
    cin >> n;   

    for(int i=0;i<n;i++){
        cin >> coins[i];
    }

    cout << optimalGame(0,n-1);

    return 0;
}