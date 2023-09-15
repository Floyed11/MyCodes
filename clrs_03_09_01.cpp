#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    int n,target;
    int nums[100000]={0};
    int index1=-1,index2=-1;
    cin>>n;
    for (int i=1;i<=n;i++) cin>>nums[i];
    cin>>target;
    int l=1,r=n;
    while (l<=r){
        int mid=(l+r)/2;
        if (nums[mid]==target){
            index1=mid;
            index2=mid;
            break;
        } 
        else if (nums[mid]<target) l=mid+1;
        else if (nums[mid]>target) r=mid-1;
    }
    if (index1==-1){
        cout<<-1<<','<<-1<<'\n';
        return 0;
    }
    while (nums[index1-1]==target){
        index1--;
    }
    while (nums[index2+1]==target){
        index2++;
    }
    cout<<index1-1<<','<<index2-1<<'\n';
    return 0;
}   