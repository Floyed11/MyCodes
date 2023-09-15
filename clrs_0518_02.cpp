#include <bits/stdc++.h>
using namespace std;

int *color;
int **graph;
int ans = 0, n;

void setcolor(int n, int c)
{
    color[n] = c;
    return;
}

void dfs(int k)
{
    if (k == n - 1)
    {
        ans++;
        setcolor(k, 0);
        return;
    }
    setcolor(k, 1);
    for (int i = 0; i < n; i++)
    {
        if (graph[k][i] == 1)
            if (color[i] == 0)
            {
                dfs(i);
                setcolor(i, 0);
            }
    }
    setcolor(k, 2);
    return;
}

int main()
{
    cin >> n;
    color = new int[n];
    graph = new int *[n];
    for (int i = 0; i < n; i++)
    {
        graph[i] = new int[n];
        color[i] = 0;
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];
    }
    dfs(0);
    cout<<ans<<endl;
    return 0;
}