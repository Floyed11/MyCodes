#include<iostream>
#include<vector>
using namespace std;
void insert(vector<int> &a,int index)
{
    int k=index;
    if(k<0)
        k=-index;
    if(a[k%a.size()]==1000000000){
        a[k%a.size()]=index;
    }else{
        for(int i=(k%a.size()==a.size()-1?0:k%a.size()+1);i!=k%a.size();i=(i==a.size()-1?0:i+1)){
            if(a[i]==1000000000)
            //不加大括号真的6
                a[i]=index;
                break;
        }
    }
    return;
}
bool search(vector<int> &a,int index)
{
    int k=index;
    if(k<0)
        k=-index;
    if(a[k%a.size()]==index)
        return true;
    if(a[k%a.size()]==1000000000)
        return false;
    for(int i=(k%a.size()==a.size()-1?0:k%a.size()+1);i!=k%a.size();i=(i==a.size()-1?0:i+1)){
        if(a[i]==1000000000)
            return false;
        if(a[i]==index)
            return true;
    }
    return false;
}
int main()
{
    int n,index;
    char m;
    cin>>n;
    vector<int> a(100000,1000000000);
    for(int i=1;i<=n;i++){
        cin>>m>>index;
        if(m=='I'){
            insert(a,index);
        }else{
            if(search(a,index)==true){
                cout<<"Yes"<<endl;
            }else{
                cout<<"No"<<endl;
            }
        }
    }
    return 0;
}