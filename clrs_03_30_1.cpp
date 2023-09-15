#include<iostream>
using namespace std;

int do_plus(int x,int y){
    if (y>0) return (x+(do_plus(x,y-1)));
    else if (y<0) return (do_plus(x,y+1)-x);
    else return 0;
}

int main(){
    int m,n;
    int ans=0;
    cin>>m>>n;
    //if (((m<0)&&(n>0))||((m>0)&&(n<0))) cout<<'-';
    ans = do_plus(m,n);
    cout<<ans<<'\n';
    return 0;
}