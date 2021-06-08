#include <bits/stdc++.h>
using namespace std;

bool subsetSumEasy(const vector<int> &v, int i = 0, int sum = 0, bool included = false)
{
    if (i == v.size())
    {
        return (sum == 0 && included);
    }

    bool inc = subsetSumEasy(v, i + 1, sum + v[i], true);
    bool exc = subsetSumEasy(v, i + 1, sum, included);

    return inc || exc;
}

int main()
{
    int testCases;
    cin >> testCases;
    while (testCases--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        if (subsetSumEasy(v))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }

    return 0;
}

// or
void func(int ind, int sum, vector <int> &arr, int N, vector <int> &sumSubset) {
    if(ind == N) {
        sumSubset.push_back(sum);
    }

    // pick
    func(ind+1, sum +arr[ind], arr, N, sumSubset);
    // not pick
    func(ind+1, sum, arr, N, sumSubset);
}


vector <int> subsetSums(vector <int> &arr , int N) {
    vector <int> sumSubset;
    func(0, 0, arr, N ,sumSubset);
    sort(sumSubset.begin(), sumSubset.end());

    return sumSubset;
}