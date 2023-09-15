#include <bits/stdc++.h>
using namespace std;
#define MAX 0
typedef struct arcnode
{
    int index;
    double weight;
    arcnode *next;
} arcnode;

typedef struct vnode
{
    int data;
    arcnode *firstarc;
} vnode;

typedef struct
{
    vnode adjlist[10010];
    int n, m;
} graph;

typedef struct
{
    double d;
    int parent;
    int data;
} vertex;

bool Relax(graph g, vertex *u, vertex *v, double w)
{
    if ((u->d * w )> v->d){
        v->d = (u->d * w);
        v->parent = u->data;
        return true;
    }
    //cout << u->data<<' '<< u->d <<' '<< v->data << ' ' << v->d << endl;
    return false;
}

bool operator<(const vertex a, const vertex b)
{
    return a.d < b.d;
}

double Dijkstra(graph g, int start, int end)
{
    vertex *u = new vertex[g.n];
    for (int i = 0; i < g.n; i++)
    {
        u[i].d = MAX;
        u[i].parent = -1;
        u[i].data = i;
    }
    priority_queue<vertex, vector<vertex>, less<vertex> > q;
    u[start].d = 1;
    for (int i = 0; i < g.n; i++)
    {
        q.push(u[i]);
    }
    while (!q.empty())
    {
        vertex head = q.top();
        q.pop();
        //cout << g.adjlist[0].firstarc->index << endl;
        arcnode *temp_node = g.adjlist[head.data].firstarc;
        //cout<< temp_node->index << endl;
        while (temp_node != NULL)
        {
            bool flag = Relax(g, &head, &u[temp_node->index], temp_node->weight);
            if (flag)
                q.push(u[temp_node->index]);
            temp_node = temp_node->next;
        }
    }
    return u[end].d;
}

int main()
{
    graph g;
    cin >> g.n >> g.m;
    for (int i = 0; i < g.n; i++)
    {
        g.adjlist[i].firstarc = NULL;
    }
    for (int i = 0; i < g.m; i++)
    {
        int u, v;
        double w;
        cin >> u >> v >> w;
        arcnode *temp = new arcnode;
        temp->index = v;
        temp->weight = w;
        temp->next = NULL;
        if (g.adjlist[u].firstarc == NULL)
        {
            g.adjlist[u].firstarc = temp;
        }
        else
        {
            arcnode *p = g.adjlist[u].firstarc;
            while (p->next != NULL)
            {
                p = p->next;
            }
            p->next = temp;
        }

        temp = new arcnode;
        temp->index = u;
        temp->weight = w;
        temp->next = NULL;
        if (g.adjlist[v].firstarc == NULL)
        {
            g.adjlist[v].firstarc = temp;
        }
        else
        {
            arcnode *p = g.adjlist[v].firstarc;
            while (p->next != NULL)
            {
                p = p->next;
            }
            p->next = temp;
        }
        //cout<<g.adjlist[u].firstarc->index<<endl;
    }
    int start, end;
    cin >> start >> end;
    cout << Dijkstra(g, start, end) << endl;
}