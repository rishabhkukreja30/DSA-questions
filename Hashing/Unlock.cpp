#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,k;
    cin >> n >> k;
    vector<int> v;
    unordered_map<int,int> m ;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        v.push_back(x);
        m[v[i]] = i ;
    }
    for(int i=0;i<n && k>0;i++){
        int pos = n - i;
        if(v[i] == pos){
            //Already correct element
            continue;
        }
        int index = m[pos];
        m[v[i]] = index ;  //update in map
        m[pos] = i;
        swap(v[i],v[index]);
        k--;
    }
    for(int i=0;i<n;i++){
        cout << v[i] << " ";
    }

    return 0;
}