#include<bits/stdc++.h>
using namespace std;

class node {
public:
	int data;
	node* left;
	node* right;

	node(int d) {
		data = d;
		left = right = NULL;
	}
};

//pass it by reference
void verticalOrderPrint(node* root, int d, map <int , vector <int> > &m) {
	//base case
	if(root == NULL) {
		return;
	}
	//otherwise
	m[d].push_back(root->data);
	verticalOrderPrint(root->left, d-1,m);
	verticalOrderPrint(root->right, d+1, m);
	return;
}


int main() {

	node* root = new node(1);

	root->left = new node(2);
	root->right = new node(3);
	root->left->left = new node(4);
	root->left->right = new node(5);

	root->right->left = new node(6);
	root->right->right = new node(7);

	root->right->right->right = new node(9);
	root->left->right->right = new node(8);

	map < int, vector <int> > m;
	int d=0;
	verticalOrderPrint(root, d, m);

	for(auto p : m) {
		// cout<<p.first<<"->";
		for(int x: p.second) {
			cout<<x<<" ";
		}
		cout<<endl;
	}

	return 0;

}




// or
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map <int, vector <int> > m;
        vector<vector<int>> ans;
        
        queue <pair <TreeNode*, int>> q;
        int minh = 0;
        int maxh = 0;
        
        q.push({root, 0});
        
        while(!q.empty()) {
            pair p = q.front();
            q.pop();

            
            m[p.second].push_back(p.first->val);
            
            if(p.first->left) {
                q.push({p.first->left, p.second-1});
            }
            
            if(p.first->right) {
                q.push({p.first->right, p.second+1});
            }
        }
        
        for(auto x : m) {
            ans.push_back(x.second);
        }
        
        return ans;
    }


    