

    void func(int idx, int sum, vector <int> &arr, int N, vector <int> &ans) {
        
        if(idx == N) {
            ans.push_back(sum);
            return;
        }
        func(idx+1, sum+arr[idx], arr, N, ans);
        func(idx+1, sum, arr, N, ans);
    }

    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector <int> ans;
        func(0 ,0, arr, N, ans);
        sort(ans.begin(), ans.end());
        return  ans;
    }