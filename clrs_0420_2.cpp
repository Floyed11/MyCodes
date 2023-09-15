#include <bits/stdc++.h>
using namespace std;

typedef struct node_def
{
    int key;
    int num;
} node;

bool cmp(node a, node b)
{
    return a.key < b.key;
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
    return;
}

void heapify(node heap[], int node, int size)
{
    int left = node * 2;
    int right;
    if (left > size)
    {
        return;
    }
    else if (left == size)
    {
        right = left;
    }
    else
    {
        right = left + 1;
    }
    int min = node;
    if (heap[left].num < heap[min].num)
    {
        min = left;
    }
    if (heap[right].num < heap[min].num)
    {
        min = right;
    }
    if (min != node)
    {
        swap(heap[node], heap[min]);
        heapify(heap, min, size);
    }
    return;
}

void build_heap(node heap[], int size)
{
    for (int i = int(size / 2); i >= 1; i--)
    {
        heapify(heap, i, size);
    }
    return;
}

int main()
{
    int n;
    cin >> n;
    int nums[n + 5];
    node heap[n + 5],tmp[n+5];
    int p=0;
    int cnt[100010],flag[100010];
    memset(cnt, 0, sizeof(cnt));
    memset(flag, 0, sizeof(flag));
    for (int i = 1; i <= n; i++)
    {
        cin >> nums[i];
        cnt[nums[i]]++;
    }
    int k;
    cin >> k;
    for (int i=1;i<=n;i++){
        if (cnt[nums[i]]>0 && flag[nums[i]]==0){
            p++;
            tmp[p].key=nums[i];
            tmp[p].num=cnt[nums[i]];
            flag[nums[i]]=1;
        }
    }
    for (int i = 1; i <= k; i++)
    {
        heap[i].key = tmp[i].key;
        heap[i].num = tmp[i].num;
    }
    build_heap(heap, k);
    for (int i = k + 1; i <= p; i++)
    {
        if (tmp[i].num > heap[1].num)
        {
            heap[1].key = tmp[i].key;
            heap[1].num = tmp[i].num;
            heapify(heap, 1, k);
        }
    }
    sort(heap + 1, heap + k + 1, cmp);
    for (int i=1;i<=k;i++){
        cout<<heap[i].key<<' ';
    }
    cout<<endl;
    return 0;
}