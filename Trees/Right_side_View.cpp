

vector <int> rightSideView(node* root) {
	
	vector<int> ans;
	if(root == NULL) {
		return ans;
	}

	queue <node*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()) {
		node* n = q.front();
		q.pop();

		if(n->left) {
			q.push(n->left);
		}
		if(n->right) {
			q.push(n->right);
		}

		if(q.front() == NULL) {
			ans.push_back(n->data);
			q.pop();
			if(!q.empty()) {
				q.push(NULL);
			}
		}
	}
	return ans;
}