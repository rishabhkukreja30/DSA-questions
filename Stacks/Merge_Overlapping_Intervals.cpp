bool comparator(pair <int, int> p1 , pair <int, int> p2) {
    return p1.first < p2.first;
}

vector<pair<int,int>> overlappedInterval(vector<pair<int,int>> vec, int n) {
    //code here
    vector<pair<int, int> > v;
    
    stack <pair <int ,int>> s;
    
    sort(vec.begin(), vec.end(), comparator);
    
    s.push(vec[0]);
    
    for(int i=1;i<n;i++) {
        pair <int, int> top = s.top();
        if(top.second < vec[i].first) {
            s.push(vec[i]);
        }
        
        else if(top.second < vec[i].second ) {
            top.second = vec[i].second;
            s.pop();
            s.push(top);
        }
    }
    
    while(!s.empty()) {
        pair <int, int> t = s.top();
        v.push_back(t);
        s.pop();
    }
    sort(v.begin(), v.end(), comparator);
    return v;
}


// without using extra space
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector <vector <int> > mergedIntervals;
        
        if(intervals.size() == 0) {
            return mergedIntervals;
        }
        
        sort(intervals.begin(),intervals.end());
        
        vector <int> tempInterval = intervals[0];
        
        for(auto it : intervals) {
            if(it[0] <= tempInterval[1]) {
                tempInterval[1] = max(it[1], tempInterval[1]);
            }
            else {
                mergedIntervals.push_back(tempInterval);
                tempInterval = it;
            }
        }
        mergedIntervals.push_back(tempInterval);
        return mergedIntervals;
    }







    


