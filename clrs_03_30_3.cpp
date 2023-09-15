#include<iostream>
#include<cmath>
using namespace std;

int robin(int m,int n){
    int x=max(m,n),y=min(m,n);
    if (y==0) return 0;
    return (robin(x-y,y)+4*y);
}

int main(){
    int x,y,z;
    cin>>x>>y;
    // if (x>y){
    //     int t=x;
    //     x=y;
    //     y=t;
    // }
    cout<<robin(x,y)<<'\n';
    return 0;
}