#include <bits/stdc++.h>
using namespace std;

typedef struct dll_node
{
    struct dll_node *prev;
    struct dll_node *next;
    int key;
} dll_node;

dll_node *make_list(int a[], int n)
{
    dll_node *l = NULL;
    dll_node *start = NULL;
    dll_node *tmp = (dll_node *)malloc(sizeof(dll_node));
    tmp->key = a[0];
    tmp->next = NULL;
    tmp->prev = NULL;
    start = tmp;
    l = tmp;
    for (int i = 1; i < n; i++)
    {
        dll_node *temp = (dll_node *)malloc(sizeof(dll_node));
        temp->key = a[i];
        temp->next = NULL;
        temp->prev = l;
        l->next = temp;
        l = temp;
    }
    return start;
}

void prt(dll_node *l)
{
    if (l != NULL)
    {
        if (l->next != NULL)
            cout << l->key << ' ';
        else
            cout << l->key;
        prt(l->next);
    }
    return;
}

dll_node *delete_node(dll_node *l, int x)
{
    dll_node *temp = l;
    dll_node *start = l;
    while (temp != NULL)
    {
        if (temp->key == x)
        {
            if (temp->prev != NULL)
                temp->prev->next = temp->next;
            if (temp->next != NULL)
                temp->next->prev = temp->prev;
            if (temp->prev == NULL)
                start = temp->next;
            free(temp);
            return start;
        }
        else
            temp = temp->next;
    }
    return start;
}

int search_node(dll_node *l, int y)
{
    dll_node *temp = l;
    while (temp != NULL)
    {
        if (temp->key == y)
        {
            if (temp->prev != NULL)
                return temp->prev->key;
            else
                return -1;
        }
        else
            temp = temp->next;
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    int input[n + 5];
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    dll_node *l_head = make_list(input, n);
    prt(l_head);
    cout << endl;
    int x;
    cin >> x;
    l_head = delete_node(l_head, x);
    prt(l_head);
    cout << endl;
    int y;
    cin >> y;
    cout << search_node(l_head, y) << endl;
    return 0;
}