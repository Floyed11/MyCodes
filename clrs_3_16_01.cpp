#include<iostream>
#include<math.h>
using namespace std;

int n,a[100010];

int merge(int l,int p,int r){
    int p1=l,p2=p+1,p0=0;
    int b[100010];
    while ((p1<=p) && (p2<=r)){
        if (a[p1]<a[p2]){
            p1++;
            b[p0]=a[p1-1];
            p0++;
        }
        else{
            p2++;
            b[p0]=a[p2-1];
            p0++;
        }
    }
    while (p1<=p){
        b[p0]=a[p1];
        p1++;
        p0++;
    }
    while (p2<=r){
        b[p0]=a[p2];
        p2++;
        p0++;
    }
    for (int i=0;i<p0;i++) a[l+i]=b[i];
    return 0;
}

int merge_sort(int l,int r){
    if (l==r) return 0;
    int mid=(l+r)/2;
    merge_sort(l,mid);
    merge_sort(mid+1,r);
    merge(l,mid,r);
    return 0;
}

int main(){
    cin>>n;
    for (int i=0;i<n;i++) cin>>a[i];
    merge_sort(0,n-1);
    for (int i=0;i<n;i++){
        cout<<a[i]<<' ';
    }
    cout<<'\n';
    return 0;
}