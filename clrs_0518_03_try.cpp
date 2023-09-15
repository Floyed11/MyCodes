#include <bits/stdc++.h>
using namespace std;

list<int> *tree;

void bfs(int n)
{
    queue<int> q;
    q.push(n);
    while (!q.empty())
    {
        int tmp = q.front();
        q.pop();
        cout << tmp << " ";
        if (!tree[tmp].empty())
            for (list<int>::iterator i = tree[tmp].begin(); i != tree[tmp].end(); i++)
            {
                q.push(*i);
            }
    }
}

int main()
{
    int n = 0;
    int key[10010];
    while (cin >> key[++n])
        ;
    tree = new list<int>[n];
    for (int i = 1; i <= n / 2; i++)
    {
        tree[i].push_back(key[i * 2]);
        tree[i].push_back(key[i * 2 + 1]);
    }
    bfs(1);
    return 0;
}