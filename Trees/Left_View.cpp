//Recursive Approach
void leftViewHelper(node *root, int level, int &max_level) {
    if(root == NULL) {
        return;
    }
    if(max_level<level) {
        cout<<root->data<<" ";
        max_level = level;
    }
    leftViewHelper(root->left, level+1, max_level);
    leftViewHelper(root->right, level+1, max_level);
}

void leftView(node *root) {
    int max_level = 0;
    leftViewHelper(root, 1, max_level);
}


// Iterative Approach
void printLeftSide(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    bool flag = true;

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
            flag = true;
        }
        else
        {
            if (flag)
            {
                cout << f->data << " ";
                flag = false;
            }
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
    return;
}