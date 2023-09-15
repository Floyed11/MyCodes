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
    int a[1010],n=0;
    Tree t;
    t.root = NULL;
    while(cin>>a[++n])
    {
        if (n == 1)
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
            insert(t.root, a[n]);
        }
    }
    floorprt(t.root);
    cout << endl;
    return 0;
}