
// recursive soln
void bottomViewHelper(node *root, int level, int dist, map<int, pair<int, int> > &mp) {
    if(root == NULL) {
        return;
    }
    if(mp.find(dist) == mp.end() or level>=mp[dist].second) {
        mp[dist] = {root->data, level};
    }
    bottomViewHelper(root->left, level+1, dist-1, mp);
    bottomViewHelper(root->right, level+1, dist+1, mp);
}
void bottomView(node *root)
{
   map<int, pair<int, int> >mp;    // horizontal dist, node->data, vertical dist
   bottomViewHelper(root, 0, 0, mp);
   for(auto val:mp){
       cout<<val.second.first<<" ";
   }
}


// iterative soln
void bottomViewIterative(node *root)
{
    queue<pair<node *, int>> qu;
    qu.push({root, 0});
    map<int, int> mp;
    while (!qu.empty())
    {
        node *temp = qu.front().first;
        int dist = qu.front().second;
        qu.pop();
        mp[dist] = temp->data;
        if (temp->left)
        {
            qu.push({temp->left, dist - 1});
        }
        if (temp->right)
        {
            qu.push({temp->right, dist + 1});
        }
    }

    for (auto x : mp)
    {
        cout << x.second << " ";
    }
}