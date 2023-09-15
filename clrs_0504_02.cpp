#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
    int key;
    node *left;
    node *right;
    node *p;
} node;

void preorder(node *root)
{
    if (root == NULL)
        return;
    cout << root->key << " ";
    preorder(root->left);
    preorder(root->right);
}

void insert(node * root,int n){
    node * tmp = (node *)malloc(sizeof(node));
    tmp->key = n;
    tmp->left = NULL;
    tmp->right = NULL;
    tmp->p = NULL;
    
    node * pre = NULL;
    node * cur = root;
    while(cur != NULL){
        pre = cur;
        if(cur->key > n){
            cur = cur->left;
        }else{
            cur = cur->right;
        }
    }
    if(pre->key > n){
        pre->left = tmp;
    }else{
        pre->right = tmp;
    }
    tmp->p = pre;
}

int main()
{
    int n;
    cin >> n;
    int a[n + 5];
    node * root = NULL;
    cin>>a[1];
    node * tmp = (node *)malloc(sizeof(node));
    tmp->key = a[1];
    tmp->left = NULL;
    tmp->right = NULL;
    tmp->p = NULL;
    root = tmp; 
    for (int i = 2; i <= n; i++){
        cin >> a[i];
        insert(root,a[i]);
    }
    int element;
    cin >> element;
    insert(root, element);
    preorder(root);
    cout<<endl;
    return 0;
}