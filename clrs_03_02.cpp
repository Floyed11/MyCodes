#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
int main(){
    string s;
    int a[30][1000]={0};
    cin>>s;
    if (s=="NULL"){
        cout<<0;
        printf("\n");
        return 0;
    }
    int len=s.size();
    a[int(s[0])-int('a')][0]=1;
    for (int i=1;i<len;i++){
        for (int j=0;j<26;j++)
            if (j==(int(s[i])-int('a'))) a[j][i]=a[j][i-1]+1;
            else a[j][i]=a[j][i-1];
    }
    int ans=0;
    for (int l=0;l<len-1;l++)
        for (int r=l+1;r<len;r++){
            int max=0,min=0;
            for (int i=0;i<26;i++){
                int temp=0;
                if (l==0) temp=a[i][r];
                else temp=a[i][r]-a[i][l-1];
                if (temp==0) continue;
                if (temp>max) max=temp;
                if ((min==0) || (temp<min)) min=temp;
            }
            ans+=max-min;
        }
    cout<<ans;
    printf("\n");
    return 0;
}