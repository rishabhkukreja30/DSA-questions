
int MinMoney(int prices[] , int n, int vidx, int cap, int dp[][]) {
    if (cap == 0) {
        return 0;
    }

    if (vidx == n) {
        return 10000000;
    }

    if (dp[vidx][cap] != -1) {
        return dp[vidx][cap];
    }

    int inc = 10000000;
    if (cap >= vidx + 1 && prices[vidx] != -1) {
        inc = MinMoney(prices, n,  vidx,  cap - vidx - 1, dp) + prices[vidx];
    }
    int exc = MinMoney(prices, n,  vidx + 1, cap, dp);

    return dp[vidx][cap] = min(inc, exc);
 }
