#include <bits/stdc++.h>
using namespace std;
#define INF 100000000;

typedef struct
{
    long x, y;
    long key;
    bool mstSet;
} Point;

typedef struct
{
    Point *p;
} Graph;

typedef struct
{
    long *index;
    long size;
} Heap;

long dist(Point p1, Point p2)
{
    return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}

void heapify(Heap &h, long i)
{
    long l = 2 * i + 1;
    long r = 2 * i + 2;
    long smallest = i;
    if (l < h.size && h.index[l] < h.index[smallest])
        smallest = l;
    if (r < h.size && h.index[r] < h.index[smallest])
        smallest = r;
    if (smallest != i)
    {
        long temp = h.index[i];
        h.index[i] = h.index[smallest];
        h.index[smallest] = temp;
        heapify(h, smallest);
    }
    return;
}

int main()
{
    long n;
    long long ans = 0;
    cin >> n;
    Graph g;
    g.p = new Point[n];
    Heap h;
    h.size = n;
    h.index = new long[n];
    for (long i = 0; i < n; i++)
    {
        cin >> g.p[i].x >> g.p[i].y;
        g.p[i].key = INF;
        h.index[i] = i;
        g.p[i].mstSet = false;
    }
    while (h.size > 0)
    {
        long u = h.index[0];
        g.p[u].mstSet = true;
        if (u != 0)
            ans += g.p[u].key;
        h.index[0] = h.index[h.size - 1];
        h.size--;
        heapify(h, 0);
        for (long i = 0; i < n; i++)
        {
            long d = dist(g.p[u], g.p[i]);
            if ((d < g.p[i].key) && (g.p[i].mstSet == false))
            {
                g.p[i].key = d;
                for (long j = h.size-1; j > 0; j = j-1)
                    heapify(h, j);
                heapify(h, 0);
            }
        }
    }
    cout << ans << endl;
    return 0;
}