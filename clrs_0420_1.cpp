#include <bits/stdc++.h>
using namespace std;

void insert_a(int a[], int key, int size)
{
    int index = key % size;
    if (a[index] == key)
        return;
    else if (a[index] == 0)
    {
        a[index] = key;
    }
    else
    {
        for (int i = (index + 1) % size; i != index; i = (i + 1) % size)
        {
            if (a[i] == 0)
            {
                a[i] = key;
                return;
            }
        }
    }
    return;
}
void delete_a(int a[], int k, int size)
{
    int index = k % size;
    if (a[index] == k)
    {
        a[index] = 0;
        return;
    }
    else if (a[index] == 0)
    {
        return;
    }
    else
    {
        for (int i = (index + 1) % size; i != index; i = (i + 1) % size)
        {
            if (a[i] == k)
            {
                a[i] = 0;
                return;
            }
        }
    }
    return;
}
int search_array(int a[], int k, int size)
{
    int index = k % size;
    if (a[index] == k)
    {
        return 1;
    }
    else if (a[index] == 0)
    {
        return 0;
    }
    else
    {
        for (int i=(index+1)%size;i!=index;i=(i+1)%size){
            if (a[i]==k){
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    int key;
    int a[n + 5];
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= n; i++)
    {
        cin >> key;
        insert_a(a, key, n);
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> key;
        delete_a(a, key, n);
    }
    for (int i = 1; i <= k; i++)
    {
        cin >> key;
        cout << search_array(a, key, n) <<' ';
    }
    cout << endl;
    return 0;
}