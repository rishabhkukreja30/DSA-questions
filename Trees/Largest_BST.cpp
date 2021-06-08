/* Check if tree with current node as root is a valid BST and if it is then return its size.
If tree with current node as its root is not a valid BST, then make recursive calls to
 left and right sub-trees and return the maximum of values returned by these recursive calls. 
 Condition for valid BST could be checked by creating inorder array and checking if it is sorted.
The worst case time complexity of above algorithm is O(n^2) which occurs when the binary tree is
 skewed one with each node having only right child which is less than its parent.

Naive Algorithm  */

bool isBST(node *root, int minV = INT_MIN, int maxV = INT_MAX)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->data >= minV && root->data <= maxV && isBST(root->left, minV, root->data) && isBST(root->right, root->data, maxV))
    {
        return true;
    }
    return false;
}

int count(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + count(root->left) + count(root->right);
}

int sizeOfMaxBST(node *root)
{
    int maxSize = 0;
    if (root == NULL)
    {
        return 0;
    }
    if (isBST(root))
    {
        maxSize = max(maxSize, count(root));
    }
    return max(maxSize, max(sizeOfMaxBST(root->left), sizeOfMaxBST(root->right)));
}





/* Optimised Approach
Now let's look at the algorithm which runs in O(n) time. The basic idea used here is that for a 
tree with root as currentNode to be a valid BST, it's left and right sub-trees have to be valid BSTs, 
value of currentNode has to be greater than the maximum valued node from its left sub-tree and
 value of currentNode has to be less than the minimum valued node from its right sub-tree.

To check for above conditions, we return value of maximum valued node, minimum valued node 
and boolean variable stating if the tree is valid BST or not from every sub-tree. 
We also return size of a sub-tree if it is a valid BST or return -1 if it is not a valid BST. 
Using these returned variables from left and right sub-trees, we can check at the currentNode if the tree 
with its root as currentNode is a validBST or not. If the tree is a valid BST, 
we calculate size of tree using (1+sizeOfLeftSubtree +sizeOfRightSubtree) and 
return that along with other variables stated above. If it is not a valid BST we return -1 along with other variables.
*/

#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

node *createTreeFromTrav(int *in, int *pre, int s, int e)
{
    static int i = 0;
    //Base Case
    if (s > e)
    {
        return NULL;
    }
    //Rec Case
    node *root = new node(pre[i]);

    int index = -1;
    for (int j = s; j <= e; j++)
    {
        if (in[j] == pre[i])
        {
            index = j;
            break;
        }
    }

    i++;
    root->left = createTreeFromTrav(in, pre, s, index - 1);
    root->right = createTreeFromTrav(in, pre, index + 1, e);
    return root;
}
class Info
{
public:
    bool is_bst;
    int maxBSTsize;
    int leftmax;
    int rightmin;
    Info()
    {
        is_bst = true;
        maxBSTsize = 0;
        leftmax = INT_MIN;
        rightmin = INT_MAX;
    }
};

Info greatestBSTinBT(node *root)
{

    if (root == NULL)
    {
        return Info();
    }

    Info left = greatestBSTinBT(root->left);
    Info right = greatestBSTinBT(root->right);
    Info ans;
    if (root->data >= left.leftmax && root->data < right.rightmin &&
        left.is_bst && right.is_bst)
    {
        ans.maxBSTsize = left.maxBSTsize + right.maxBSTsize + 1;
        ans.is_bst = true;
        ans.leftmax = max(left.leftmax, root->data);
        ans.rightmin = min(right.rightmin, root->data);
    }
    else
    {
        ans.is_bst = false;
        ans.maxBSTsize = max(left.maxBSTsize, right.maxBSTsize);
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;

    int preOrder[10000], inOrder[10000];
    for (int i = 0; i < n; i++)
    {
        cin >> preOrder[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> inOrder[i];
    }
    node *root = createTreeFromTrav(inOrder, preOrder, 0, n - 1);

    cout << greatestBSTinBT(root).maxBSTsize;
    return 0;
}