#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
    int key;
    node *left;
    node *right;
    node *p;
} node;

typedef struct que
{
    int head;
    int tail;
    node *arr[1010];
} que;

que q;

typedef struct Tree
{
    node *root;
} Tree;

node *tree_min(node *root)
{
    node *tmp = root;
    while (tmp->left != NULL)
    {
        tmp = tmp->left;
    }
    return tmp;
}

void trans(Tree & t, node *u, node *v)
{
    if (u->p == NULL)
    {
        t.root = v;
    }
    else if (u == u->p->left)
    {
        u->p->left = v;
        v->p = u->p;
    }
    else
    {
        u->p->right = v;
        v->p = u->p;
    }
    return;
}

node *del(Tree t, int m)
{
    if (t.root == NULL)
        return t.root;
    node *temp = t.root;
    while (temp != NULL && temp->key != m)
    {
        if (temp->key > m)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }
    if (temp == NULL)
        return t.root;
    if (temp->key == m)
    {
        if (temp->right == NULL && temp->left == NULL)
        {
            if (temp->p->left == temp){
                temp->p->left = NULL;
            }
            else {
                temp->p->right = NULL;
            }
        }
        else if (temp->right == NULL){
            trans(t,temp,temp->left);
        }
        else if (temp->left == NULL)
        {
            trans(t, temp, temp->right);
        }
        else
        {
            node *y = tree_min(temp->right);
            if (y->p != temp)
            {
                trans(t, y, y->right);
                y->right = temp->right;
                y->right->p = y;
            }
            trans(t, temp, y);
            y->left = temp->left;
            y->left->p = y;
        }
    }
    return t.root;
}

void preorder(node *root)
{
    if (root == NULL)
        return;
    cout << root->key << " ";
    preorder(root->left);
    preorder(root->right);
}

void insert(node *root, int n)
{
    node *tmp = (node *)malloc(sizeof(node));
    tmp->key = n;
    tmp->left = NULL;
    tmp->right = NULL;
    tmp->p = NULL;

    node *pre = NULL;
    node *cur = root;
    while (cur != NULL)
    {
        pre = cur;
        if (cur->key > n)
        {
            cur = cur->left;
        }
        else
        {
            cur = cur->right;
        }
    }
    if (pre->key > n)
    {
        pre->left = tmp;
    }
    else
    {
        pre->right = tmp;
    }
    tmp->p = pre;
}

void floorprt(node *root)
{
    if (root == NULL)
        return;
    q.arr[++q.tail] = root;
    while (q.head <= q.tail)
    {
        cout << q.arr[q.head]->key << " ";
        if (q.arr[q.head]->left != NULL)
            q.arr[++q.tail] = q.arr[q.head]->left;
        if (q.arr[q.head]->right != NULL)
            q.arr[++q.tail] = q.arr[q.head]->right;
        q.head++;
    }
    return;
}

int main()
{
    q.head = 1;
    q.tail = 0;
    int n;
    cin >> n;
    int a[1010];
    Tree t;
    t.root = NULL;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (i == 1)
        {
            node *tmp = (node *)malloc(sizeof(node));
            tmp->key = a[1];
            tmp->left = NULL;
            tmp->right = NULL;
            tmp->p = NULL;
            t.root = tmp;
        }
        else
        {
            insert(t.root, a[i]);
        }
    }
    // preorder(t.root);
    int m;
    cin >> m;
    t.root = del(t, m);
    floorprt(t.root);
    cout << endl;
    return 0;
}