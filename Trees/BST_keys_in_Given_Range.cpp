void Print(struct node *root, int k1, int k2)
{
/* base case */
if ( NULL == root )
    return;

/* Since the desired o/p is sorted, recurse for left subtree first
    If root->data is greater than k1, then only we can get o/p keys
    in left subtree */
if ( k1 < root->key )
    Print(root->left, k1, k2);

/* if root's data lies in range, then prints root's data */
if ( k1 <= root->key && k2 >= root->key )
    cout<<root->data<<" ";

/* If root->data is smaller than k2, then only we can get o/p keys
    in right subtree */
if ( k2 > root->key )
    Print(root->right, k1, k2);
}