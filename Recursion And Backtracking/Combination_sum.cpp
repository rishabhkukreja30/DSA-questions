    

        void findCombination(int idx, int target, vector <int> &candidates, vector <vector <int> > &ans, vector <int> &ds) {
            
            if(idx == candidates.size()) {
                if(target == 0) {
                    ans.push_back(ds); 
                }
                return;  
            }
            // pick an element
            if(candidates[idx] <= target) {
                ds.push_back(candidates[idx]);
                findCombination(idx, target-candidates[idx], candidates,ans, ds);
                ds.pop_back();
            }
            
            findCombination(idx+1, target, candidates, ans, ds);
        }
        
        vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            vector <vector <int >> ans;
            vector <int> ds;
            findCombination(0, target, candidates, ans, ds);
            return ans;
        }