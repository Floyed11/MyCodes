#include <bits/stdc++.h>
using namespace std;

typedef struct list_single
{
    struct list_single *next;
    int key;
} list_node;

// typedef struct list_point{
//     list_node * head;
// }list;

list_node *pop(list_node *l)
{
    list_node *temp = l;
    if (temp != NULL)
    {
        temp = temp->next;
        free(l);
    }
    return temp;
}

void prt(list_node *l)
{
    if (l != NULL)
    {
        prt(l->next);
        cout << l->key << ' ';
    }
    return;
}

int main()
{
    int n;
    list_node *l = NULL;
    cin >> n;
    int a;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        if (i < n)
            cout << a << ' ';
        else
            cout << a;
        list_node *temp;
        temp = (list_node *)malloc(sizeof(list_node));
        temp->key = a;
        temp->next = l;
        l = temp;
    }
    cout << endl;
    int cnt;
    cin >> cnt;
    if (cnt > n)
        cnt = n;
    for (int i = 0; i < cnt; i++)
    {
        l = pop(l);
    }
    prt(l);
    cout << endl;
    return 0;
}