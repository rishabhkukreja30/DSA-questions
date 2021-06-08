#include<bits/stdc++.h>
using namespace std;

class node {

public:
	int data;
	node* left;
	node* right;

	node(int d) {
		data = d;
		left = NULL;
		right = NULL;
	}
	
};

node* buildTree() {
	int d;
	cin>>d;

	if(d == -1) {
		return NULL;
	}
	node* root = new node(d);
	root->left = buildTree();
	root->right = buildTree();
	return root;
	}

//preorder
void print(node* root) {
		if(root == NULL) {
			return;
		}
		//otherwise , print root followed by subtress (children)
		cout<<root->data<<" ";
		print(root->left);
		print(root->right);
}

void printInorder(node* root) {
	if(root == NULL) {
		return;
	}
	//otherwise left root right
	printInorder(root->left);
	cout<<root->data<<" ";
	printInorder(root->right);
}

void printPostorder(node* root) {
	if(root == NULL) {
		return;
	}
	//otherwise left right root
	printPostorder(root->left);
	printPostorder(root->right);
	cout<<root->data<<" ";
}

int height(node* root) {
	if(root == NULL) {
		return 0;
	}
	int ls = height(root->left);
	int rs = height(root->right);
	return max(ls, rs) +1;
}


//top to bottom
void printKthlevel(node* root, int k) {
	if(root == NULL) {
		return;
	}
	if(k == 1){
		cout<<root->data<<" ";
		return;
	}
	printKthlevel(root->left, k-1);
	printKthlevel(root->right, k-1);
	return;
}

void printAlllevels(node* root) {
	int h = height(root);
	for(int i=1;i<=h;i++) {
		printKthlevel(root, i);
	}
	return;
}

void bfs(node* root) {
	queue <node*> q;
	q.push(root);

	while(!q.empty()) {
		node* f = q.front();
		cout<<f->data<<" ";
		q.pop();

		if(f->left) {
			q.push(f->left);
		}
		if(f->right) {
			q.push(f->right);
		}
	}
	return;
}

void bfsLevel(node* root) {
	queue <node*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()) {
		node* f = q.front();
		if(f == NULL) {
			cout<<endl;
			q.pop();
			if(!q.empty()) {
				q.push(NULL);
			}
		}
			else {
			cout<<f->data<<" ";
			q.pop();

			if(f->left) {
				q.push(f->left);
			}
			if(f->right) {
				q.push(f->right);
			}
		}
	}
	return;
}

int count(node* root) {
	if(root == NULL) {
		return 0;
	}
	return 1 + count(root->left) + count(root->right);
}

int sumOfNodes(node* root)  {
	if(root == NULL) {
		return 0;
	}
	return root->data + sumOfNodes(root->left) + sumOfNodes(root->right);

}

int diameter(node* root) {
	if(root == NULL) {
		return 0;
	}
	int h1 = height(root->left);
	int h2 = height(root->right);
	int op1 = h1 + h2;
	int op2 = diameter(root->left);
	int op3 = diameter(root->right);

	return max(op1, max(op2, op3));
}

class Pair{
public:
	int height;
	int diameter;
};

Pair fastDiameter(node* root) {
	Pair p;
	if(root == NULL) {
		p.diameter = p.height = 0;
		return p;
	}
	// otherwise 
	Pair left = fastDiameter(root->left);
	Pair right =  fastDiameter(root->right);

	p.height = max(left.height, right.height) +1;
	p.diameter = max(left.height + right.height, max(left.diameter, right.diameter));
	return p;
}

int replaceSum(node* root) {
	if(root == NULL) {
		return 0;
	}
	if(root->left == NULL && root->right == NULL) {
		return root->data;
	}
	//recursuve part
	int leftSum = replaceSum(root->left);
	int rightSum = replaceSum(root->right);

	int temp = root->data;
	root->data = leftSum + rightSum;
	return temp + root->data;
}

class HBPair {
public:
	int height;
	bool balance;
};

HBPair isHeightBalance(node* root) {
	HBPair p;
	if(root == NULL) {
		p.height = 0;
		p.balance = true;
		return p;
	}
	HBPair left = isHeightBalance(root->left);
	HBPair right = isHeightBalance(root->right);

	p.height = max(left.height , right.height) + 1;

	if(abs(left.height - right.height) <= 1 && left.balance && right.balance) {
		p.balance = true;
	}
	else{
		p.balance = false;
	}
	return p;
}

node* buildTreeFromArray(int *a, int s, int e) {
	//base case
	if(s > e) {
		return NULL;
	}
	//recursive case
	int mid = (s + e) / 2;
	node* root = new node(a[mid]);
	root->left = buildTreeFromArray(a, s, mid - 1);
	root->right = buildTreeFromArray(a, mid + 1, e);
	return root;
}


node* createFromInorderPreorder(int* in, int* pre, int s, int e) {
	static int i = 0;
	//base case
	if(s > e) {
		return NULL;
	}
	//rec case
	node* root = new node(pre[i]);

	int index = -1;
	for(int j =s;s<=e;j++) {
		if(in[j] == pre[i]) {
			index = j;
			break;
		}
	}
	i++;
	root->left = createFromInorderPreorder(in ,pre, s, index -1);
	root->right = createFromInorderPreorder(in, pre, index +1, e);
	return root;
}

// maxlevel is passed by reference bcoz we want to know what is the global max till this point in the tree
void printRightView(node* root, int level ,int &maxlevel) {
	if(root == NULL) {
		return;
	}
	if(maxlevel < level) {
		//we have discovered a new level
		cout<<root->data<<" ";
		maxlevel = level;
	}
	//right
	//left
	printRightView(root->right, level +1, maxlevel);
	printRightView(root->left, level +1, maxlevel);
}

void printAtLevelK(node* root, int k) {
	if(root == NULL) {
		return;
	}
	if(k == 0) {
		cout<<root->data<<" ";
		return;
	}
	printAtLevelK(root->left, k-1);
	printAtLevelK(root->right, k-1);
	return;
}

// return type of this function is int to return the distance of every node from target node
int printAtDistanceK(node* root, node* target, int k) {
	//base case
	if(root == NULL) {
		return -1;
	}
	//reach the target node
	if(root == target) {
		printAtLevelK(target, k);
		return 0;
	}
	//now we go to ancesstor
	int DL = printAtDistanceK(root->left, target ,k);

	if(DL != -1) {
		//again there are two cases
		//ancesstor itself or you need to go to the right ancesstor
		if(DL + 1 == k) {
			cout<<root->data<<" ";
		}
		else {
			printAtLevelK(root->right, k-2-DL);
		}
		return 1 + DL;
	}
	int DR = printAtDistanceK(root->right, target, k);
	if(DR != -1) {
		if(DR+1 == k) {
			cout<<root->data<<" ";
		}
		else {
			printAtLevelK(root->left, k-2-DR);
		}
		return 1 + DR;
	}
	//node was not present in left and right subtree of given node
	return -1;
}


//assumption both a and b are present in the tree , all keys are unique
node* lca(node* root, int a, int b) {
	if(root == NULL) {
		return NULL;
	}
	if(root->data == a or root->data == b) {
		return root;
	}
	//search in left and right subtrees
	node* leftans = lca(root->left, a,b);
	node* rightans = lca(root->right, a, b);

	if(leftans != NULL and rightans != NULL) {
		return root;
	}

	if(leftans != NULL) {
		return leftans;
	}
	return rightans;
}

class maxPair{
public:
	int branchSum;
	int maxSum;

	maxPair() {
		branchSum = 0;
		maxSum = 0;
	}
};

maxPair maxSumPath(node* root) {
	maxPair p;

	if(root == NULL) {
		return p;
	}
	maxPair left = maxSumPath(root->left);
	maxPair right = maxSumPath(root->right);

	//construct two values
	int op1 = root->data;
	int op2 = left.branchSum + root->data;
	int op3 = right.branchSum + root->data;
	int op4 = left.branchSum + right.branchSum + root->data;

	int current_ans_through_root = max(op1, max(op2, max(op3, op4)));

	//branch sum of the current root
	p.branchSum = max(left.branchSum, max(right.branchSum, 0)) + root->data;
	p.maxSum = max(left.maxSum, max(right.maxSum, current_ans_through_root));
	return p;
}

//finding the level of a given node from the root node/any given node
int search(node* root, int key, int level) {
	if(root == NULL) {
		return -1;
	}
	if(root->data == key) {
		return level;
	}
	int left = search(root->left, key, level+1);
	if(left != -1) {
		return left;
	}
	return search(root->right, key, level+1);
}

//function to find distance between 2 nodes
int findDistance(node* root, int a, int b) {
	
	node* lca_node = lca(root, a, b);

	int l1 = search(lca_node, a, 0);
	int l2 = search(lca_node, b, 0);

	return l1 + l2;
}


int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	node* root = buildTree();
	print(root);
	cout<<endl;

	printInorder(root);
	cout<<endl;

	printPostorder(root);
	cout<<endl;

	cout<<height(root)<<endl;

	printAlllevels(root);
	cout<<endl;

	bfs(root);
	cout<<endl;

	bfsLevel(root);


	cout<<count(root)<<endl;

	cout<<sumOfNodes(root)<<endl;

	cout<<diameter(root)<<endl;

	Pair p = fastDiameter(root);
	cout<<p.height<<endl;
	cout<<p.diameter<<endl;


	node* target = root->left->left;

	//print the root

	printAtDistanceK(root, target, 2);
	cout<<endl;

	int A = 9;
	int B = 13;
	cout<<lca(root, A, B)->data<<endl;
	cout<<lca(root, 1, 7)->data<<endl;

	cout<<maxSumPath(root).maxSum<<endl<<endl;

	cout<<findDistance(root, 9, 14)<<endl<<endl;

	replaceSum(root);
	bfsLevel(root);

	if(isHeightBalance(root).balance) {
		cout<<"Balanced"<<endl;
	}
	else {
		cout<<"Not a balanced tree"<<endl;
	}

	int a[] = {1,2,3,4,5,6,7};
	int n = 7;

	node* root1 = buildTreeFromArray(a, 0, n-1);
	bfs(root1);
	cout<<endl;

	int in[] = {3,2,8,4,1,6,7,5};
	int pre[] = {1,2,3,4,8,5,6,7};
	int n1 = sizeof(in)/sizeof(int);

	node* root2 = createFromInorderPreorder(in , pre, 0, n1-1);
	bfs(root2);
	cout<<endl;

	int maxlevel = -1;
	printRightView(root2, 0, maxlevel);
	cout<<endl;


	

	return 0;
}