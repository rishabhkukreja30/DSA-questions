vector <int> zigZagTraversal(Node* root)
{
    // Code here
    vector <int> ans;
    if(root == NULL) {
        return ans;
    }
    
    stack <Node*> current_level;
    stack <Node*> next_level;
    
    current_level.push(root);
    
    bool leftToRight = true;
    
    while(!current_level.empty()) {
        Node* temp = current_level.top();
        current_level.pop();
        
        if(temp) {
            ans.push_back(temp->data);
            
            if(leftToRight) {
                if(temp->left) {
                    next_level.push(temp->left);
                }
                if(temp->right) {
                    next_level.push(temp->right);
                }
            }
            else {
                if(temp->right) {
                    next_level.push(temp->right);
                }
                if(temp->left) {
                    next_level.push(temp->left);
                }
            }
        }
        if(current_level.empty()) {
            leftToRight = !leftToRight;
            swap(current_level, next_level);
        }
    }
    
    return ans;
}


    // OR
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(!root)   return res;
        vector<int>row;
        queue<TreeNode*>q;
        int x=0;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode*root=q.front();
                q.pop();
                row.push_back(root->val);
                if(root->left!=NULL)
                    q.push(root->left);
                if(root->right!=NULL)
                    q.push(root->right);
            }
            if(x%2==0)
                res.push_back(row);
            else
            {
                reverse(row.begin(),row.end());
                res.push_back(row);
            }
            row.clear();
            x+=1;
        }
        return res;
    }