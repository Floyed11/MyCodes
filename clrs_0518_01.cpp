#include<bits/stdc++.h>
using namespace std;

int color[1010]={0};
list <int> course[1010];
int flag=1;

void setcolor(int n,int c){
    color[n] =c;
    return;
}

void dfs(int n){
    setcolor(n,1);
    for (list<int>::iterator i = course[n].begin(); i != course[n].end(); i++){
        if (color[*i]==0)
            dfs(*i);
        else if (color[*i]==1){
            flag=-1;
            return;
        }
    }
    setcolor(n,2);
    return;
}

int main(){
    int numCourses;
    cin >> numCourses;
    for (int i = 0; i < numCourses; i++){
        int n,m;
        int cnt;
        cin >> n >> cnt;
        for (int j = 0; j < cnt; j++){
            cin >> m;
            course[n].push_back(m);
        }
    }
    for(int i=0;i<numCourses;i++){
        if (color[i]==0)
            dfs(i);
    }
    cout<<flag<<endl;
    return 0;
}