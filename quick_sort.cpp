#include<iostream>
using namespace std;

void sort(int a[],int l,int r){
    if (l>=r){
        return;
    }
    int pilot=l;
    int pl=l,pr=r;
    while(pl<pr){
        while(a[pl]<=a[pilot] && pl<=r){
            pl++;
        }
        while(a[pr]>a[pilot] && pr>=l){
            pr--;
        }
        if (pl<pr){
            int tmp=a[pl];
            a[pl]=a[pr];
            a[pr]=tmp;
        }
    }
    int tmp=a[pl-1];
    a[pl-1]=a[pilot];
    a[pilot]=tmp;
    sort(a,l,pl-2);
    sort(a,pl,r);
    return;
}

int main(){
    int n,a[10001];
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,0,n-1);
    for (int i=0;i<n;i++){
        cout<<a[i]<<' ';
    }
    cout<<'\n';
    return 0;
}