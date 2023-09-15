#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
    int key;
    node *left;
    node *right;
    node *p;
} node;

node *make(int a[], int b[], int start, int end, int m, int n)
{
    node * tmp = NULL;
    if (start > end || m > n)
        return tmp;
    node *root = (node *)malloc(sizeof(node));
    root->key = b[end];
    //cout<<start<<' '<<end<<endl;
    for (int i = m; i <= n; i++)
    {
        if (b[end] == a[i])
        {
            root->left = make(a, b, start, start + i - m-1, m, i - 1);
            root->right = make(a, b, start + i - m, end - 1, i + 1, n);
            break;
        }
    }
    return root;
}

void preorder(node *root)
{
    if (root == NULL)
        return;
    cout << root->key << " ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    int n;
    cin >> n;
    int a[n + 5], b[n + 5];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    node *root = make(a, b, 1, n, 1, n);
    preorder(root);
    cout << endl;
    return 0;
}