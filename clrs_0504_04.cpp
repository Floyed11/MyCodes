#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
    int key;
    node *left;
    node *right;
    node *p;
} node;

struct Tree
{
    node *root;
} Tree;

node *t[1010];

node *make_tree(int a[], int n)
{
    // node * temp = (node *)malloc(sizeof(node));
    // temp->key = a[1];
    // temp->p = NULL;
    // node * root = temp;
    node *root = NULL;
    int i = 1;
    int p = 2;
    while (p <= n)
    {
        if (a[i] == -1)
        {
            i++;
            continue;
        }
        if (i == 1)
        {
            t[i] = (node *)malloc(sizeof(node));
            t[i]->key = a[i];
            t[i]->p = NULL;
            root = t[i];
        }
        if ((p <= n) && a[p] != -1)
        {
            t[p] = (node *)malloc(sizeof(node));
            t[p]->key = a[p];
            t[i]->left = t[p];
            t[p]->p = t[i];
            t[p]->left = NULL;
            t[p]->right = NULL;
            p++;
        }
        else if (a[p] == -1)
        {
            t[i]->left = NULL;
            p++;
        }
        if ((p <= n) && a[p] != -1)
        {
            t[p] = (node *)malloc(sizeof(node));
            t[p]->key = a[p];
            t[i]->right = t[p];
            t[p]->p = t[i];
            t[p]->left = NULL;
            t[p]->right = NULL;
            p++;
        }
        else if ((p <= n) && a[p] == -1)
        {
            t[i]->right = NULL;
            p++;
        }
        i++;
    }
    return root;
}

int cut(node *root)
{
    if (root->left == NULL && root->right == NULL)
    {
        if (root->key == 0)
        {
            return 1;
        }
        else
            return 0;
    }
    else if (root->left == NULL)
    {
        if (cut(root->right))
        {
            root->right = NULL;
            if (root->key == 0)
                return 1;
            else
                return 0;
        }
        else
            return 0;
    }
    else if (root->right == NULL)
    {
        if (cut(root->left))
        {
            root->left = NULL;
            if (root->key == 0)
                return 1;
            else
                return 0;
        }
        else
            return 0;
    }
    else
    {
        int f1=cut(root->left);
        int f2=cut(root->right);
        if (f1)
        {
            root->left = NULL;
        }
        if (f2)
        {
            root->right = NULL;
        }
        if (f1 && f2){
            if (root->key == 0)
                return 1;
            else
                return 0;
        }
        else{
            return 0;
        }
    }
    return 0;
}

void inorder(node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->key << ' ';
    inorder(root->right);
}

int main()
{
    int n;
    cin >> n;
    int a[n * 2 + 10];
    int i = 1;
    while (cin >> a[i])
    {
        i++;
    }
    n = i - 1;
    for (int i = 1; i <= n; i++)
    {
        t[i] = NULL;
    }
    node *root = make_tree(a, n);
    cut(root);
    inorder(root);
    cout << endl;
    return 0;
}