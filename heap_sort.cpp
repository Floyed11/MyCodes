#include <iostream>
using namespace std;
void heapify(int a[], int i, int k)
{
    int top = i;
    int l = i * 2 + 1;
    int r = l + 1;
    if (l>=k){
        return;
    }
    if (l == k - 1)
    {
        r = k - 1;
    }
    if (a[l] > a[top])
    {
        top = l;
    }
    if (a[r] > a[top])
    {
        top = r;
    }
    if (top != i)
    {
        int tmp = a[i];
        a[i] = a[top];
        a[top] = tmp;
        heapify(a, top, k);
    }
    return;
}
void build_heap(int a[], int k)
{
    for (int i = int(k / 2 - 1); i >= 0; i--)
    {
        heapify(a, i, k);
    }
    return;
}
void heap_sort(int a[], int n)
{
    for (int i = n - 1; i > 0; i--)
    {
        build_heap(a, i + 1);
        int tmp = a[0];
        a[0] = a[i];
        a[i] = tmp;
        // for (int j = 0; j < n; j++)
        // {
        //     cout << a[j] << ' ';
        // }
        // cout << '\n';
    }
    return;
}

int main()
{
    int n, a[10001];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    heap_sort(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << ' ';
    }
    cout << '\n';
    return 0;
}