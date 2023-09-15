#include<bits/stdc++.h>
using namespace std;

typedef struct queue_point
{
    int head,tail;
}queue_arr;


int main(){
    int n;
    cin>>n;
    int input[n+5];
    queue_arr q;
    q.head = 0;
    q.tail = 0;
    for(int i=0;i<n;i++){
        cin>>input[i];
        if (i != n-1)
            cout<<input[i]<<' ';
        else
            cout<<input[i];
        q.tail++;
    }
    cout<<endl;
    int x;
    cin>>x;
    if (x>n)
        x = n;
    for (int i = 0; i < x; i++)
    {
        q.head++;
    }
    for (int i=q.head;i<q.tail;i++){
        if (i != q.tail-1)
            cout<<input[i]<<' ';
        else
            cout<<input[i];
    }
    cout<<endl;
    return 0;
}