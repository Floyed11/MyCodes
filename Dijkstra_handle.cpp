#include <iostream>
#include <cmath>
using namespace std;
#define MAX 0

typedef struct arcnode
{
    int index;
    float weight;
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
    float d;
    // int parent;
    int data;
} vertex;

vertex *u = NULL;

void heapify(int queue[], int queue_size, int i)
{
    int l = 2 * i;
    int r = 2 * i + 1;
    int biggest = i;
    if (l <= queue_size && u[queue[l]].d > u[queue[biggest]].d)
        biggest = l;
    if (r <= queue_size && u[queue[r]].d > u[queue[biggest]].d)
        biggest = r;
    if (biggest != i)
    {
        int temp = queue[i];
        queue[i] = queue[biggest];
        queue[biggest] = temp;
        heapify(queue, queue_size, biggest);
    }
    return;
}

void init_queue(int *queue, int &queue_size)
{
    for (int i = queue_size / 2; i >= 1; i--)
    {
        heapify(queue, queue_size, i);
    }
}

void Relax(graph g, vertex *u, vertex *v, float w, int *queue, int &queue_size)
{
    if ((u->d * w) > v->d)
    {
        v->d = (u->d * w);
        init_queue(queue, queue_size);
        return;
    }
    // cout << u->data<<' '<< u->d <<' '<< v->data << ' ' << v->d << endl;
    return;
}

double Dijkstra(graph g, int start, int end)
{
    u = new vertex[g.n];
    int *queue = new int[g.n + 5];
    for (int i = 0; i < g.n; i++)
    {
        u[i].d = MAX;
        // u[i].parent = -1;
        u[i].data = i;
        queue[i + 1] = i;
    }
    u[start].d = 1;
    int queue_size = g.n;
    init_queue(queue, queue_size);
    while (queue_size > 0)
    {
        vertex head = u[queue[1]];
        queue[1] = queue[queue_size];
        queue_size--;
        heapify(queue, queue_size, 1);
        // cout << g.adjlist[0].firstarc->index << endl;
        arcnode *temp_node = g.adjlist[head.data].firstarc;
        // cout<< temp_node->index << endl;
        while (temp_node != NULL)
        {
            Relax(g, &head, &u[temp_node->index], temp_node->weight, queue, queue_size);
            // if (flag)
            //     q.push(u[temp_node->index]);
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
        float w;
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

        arcnode *temp0 = new arcnode;
        temp0->index = u;
        temp0->weight = w;
        temp0->next = NULL;
        if (g.adjlist[v].firstarc == NULL)
        {
            g.adjlist[v].firstarc = temp0;
        }
        else
        {
            arcnode *p = g.adjlist[v].firstarc;
            while (p->next != NULL)
            {
                p = p->next;
            }
            p->next = temp0;
        }
        // cout<<g.adjlist[u].firstarc->index<<endl;
    }
    int start, end;
    cin >> start >> end;
    cout << Dijkstra(g, start, end) << endl;
    return 0;
}