int sum = 0;   // global variable to store final answer
// O(n)
void traverseTree(node *root, int k)
{
    if (root == NULL)
    {
        return;
    }
    if (k == 0)
    {
        sum += root->data;
        return;
    }
    traverseTree(root->left, k - 1);
    traverseTree(root->right, k - 1);
}



// Optimised approach - O(n) - bcoz iterative soln is faster than recursive soln 

int sumAtLevelK(node *root, int k)
{
    if (root == NULL)
        return 0;

    int ans = 0;

    queue<node *> q;
    q.push(root);
    q.push(NULL);
    bool flag = false;

    while (!q.empty())
    {
        node *f = q.front();
        if (f == NULL)
        {
            q.pop();
            if (!q.empty())
            {
                q.push(NULL);
            }
            k--;
            if (flag)   // means sum at level k is found and then we can break out of loop
                break;
            if (k == 0)
                flag = true;
        }
        else
        {
            if (flag)
                ans += f->data;
            q.pop();

            if (f->left)
            {
                q.push(f->left);
            }
            if (f->right)
            {
                q.push(f->right);
            }
        }
    }

    return ans;
}
