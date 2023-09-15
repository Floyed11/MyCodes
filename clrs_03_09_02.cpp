#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int a[30][1000]={0};

int search(int x,int p){
    int r=a[x][0],l=1,mid=0;
    while (l<=r){
        mid=(l+r)/2;
        if (a[x][mid]==p) {
            l=mid+1;
            break;
        }
        if (a[x][mid]<=p) l=mid+1;
        if (a[x][mid]>p) r=mid-1;
    }
    if (l > a[x][0]) return -1;
    else return a[x][l];
}

int main(){
    string s,words;
    int n,total=0;
    cin>>s;

    for (int i=0;i<s.length();i++){
        a[s[i]-int('a')][0]++;
        a[s[i]-int('a')][a[s[i]-int('a')][0]]= i;
    }
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>words;
        int p=0,flag=1,index=-1;
        for (int j=0;j<words.length();j++){
            index = search(words[j]-97,index);
            if (index == -1) {
                flag=0;
                break;
            } 
        }
        if (flag==1) total++;
    }
    cout<<total<<'\n';
    return 0;
}