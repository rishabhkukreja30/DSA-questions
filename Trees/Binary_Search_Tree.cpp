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

//accepts the old root node & data and returns the  new root data
node* insertInBST(node* root, int data) {
	//base case
	if(root == NULL) {
		return new node(data);
	}
	//rec case - insert in the subtree and update pointers
	if(data <= root->data) {
		root->left = insertInBST(root->left, data);
	}
	else {
		root->right = insertInBST(root->right, data);
	}
	return root;
}

node* build() {
	//read a list of numbers till -1 and also these numbers will be inserted into BST
	int d;
	cin>>d;

	node* root = NULL;

	while(d != -1) {
		root = insertInBST(root, d);
		cin>>d;
	}
	return root;
}


//print the BST level by level
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

//inorder print
void inorder(node* root) {
	if(root == NULL) {
		return;
	}
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

bool search(node* root, int data) {
	if(root == NULL) {
		return false;
	}
	if(root->data == data) {
		return true;
	}
	//recursively search in left and right subtree
	if(data <= root->data) {
		return search(root->left, data);
	}
	else {
		return search(root->right, data);
	}
}

node* deleteInBST(node* root, int data) {
	if(root == NULL) {
		return NULL;
	}
	else if(data < root->data) {
		root->left = deleteInBST(root->left, data);
		return root;
	}
	else if(data == root->data) {
		//found the node to delete 3 cases
		//1. node with 0 children - leaf node
		if(root->left == NULL && root->right == NULL) {
			delete root;
			return NULL;
		}
		//2. only 1 child
		if(root->left != NULL && root->right == NULL) {
			node* temp = root->left;
			delete root;
			return temp;
		}
		if(root->right != NULL && root->left == NULL) {
			node* temp = root->right;
			delete root;
			return temp;
		}
		//3. 2 children
		node* replace  = root->right;
		//find the inorder successor from right subtree
		while(replace->left != NULL) {
			replace = replace->left;
		}

		root->data = replace->data;
		root->right = deleteInBST(root->right, replace->data);
		return root;
	}
	else {
		root->right = deleteInBST(root->right , data);
		return root;
	}

}

bool isBST(node* root, int minV = INT_MIN , int maxV = INT_MAX) {
	if(root == NULL) {
		return true;
	}
	if(root->data >= minV && root->data <= maxV && isBST(root->left, minV, root->data) && isBST(root->right, root->data, maxV)) {
		return true;
	}
	return false;
}


class LinkedList {
public:
	node* head;
	node* tail;
};

LinkedList flatten(node* root) {
	LinkedList l;

	if(root == NULL) {
		l.head = l.tail = NULL;
		return l;
	}
	//leaf node
	if(root->left == NULL && root->right == NULL) {
		l.head = l.tail = root;
		return l;
	}
	//left is not NULL
	if(root->left != NULL && root->right == NULL) {
		LinkedList leftLL = flatten(root->left);
		leftLL.tail->right = root;

		l.head = leftLL.head;
		l.tail = root;
		return l;
	}
	// right is not NULL
	if(root->left == NULL && root->right != NULL) {
		LinkedList rightLL = flatten(root->right);
		root->right = rightLL.head;

		l.head = root;
		l.tail = rightLL.tail;
		return l;
	}
	//both sides are not NULL
	LinkedList leftLL = flatten(root->left);
	LinkedList rightLL = flatten(root->right);

	leftLL.tail->right = root;
	root->right = rightLL.head;

	l.head = leftLL.head;
	l.tail = rightLL.tail;

	return l;
}

int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	node* root = build();
	inorder(root);
	cout<<endl;
	bfs(root);
	cout<<endl;

	int s;
	cin>>s;

	if(search(root, s)) {
		cout<<"Present"<<endl;
	}
	else {
		cout<<"Not present"<<endl;
	}

	if(isBST(root)) {
		cout<<"Yes"<<endl;
	}
	else {
		cout<<"Not a BST"<<endl;
	}

	int s1;
	cin>>s1;

	root = deleteInBST(root,s1);
	inorder(root);
	cout<<endl;
	bfs(root);
	cout<<endl;


	LinkedList l = flatten(root);
	node* temp = l.head;

	while(temp != NULL) {
		cout<<temp->data<<"--> ";
		temp = temp->right;
	}
	cout<<endl;

	

	return 0;
}