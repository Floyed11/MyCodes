#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
string s;
int a[10010]={0},p1=0,nums[100010]={0},p2=0,p0=0;
char ope[100010];
struct ret
{
    int b[100010];
    int cnt;
};

ret doit(int l,int r){
    // if (l==r){
    //     if (ope[l]=='+')
    //         return a[l]+a[l+1];
    //     if (ope[l]=='-')
    //         return a[l]-a[l+1];
    //     if (ope[l]=='*')
    //         return a[l]*a[l+1];
    //     if (ope[l]=='/')
    //         return a[l]/a[l+1];    
    // }
    ret ans0;ans0.cnt=0;
    for (int i=l;i<=r;i++){
        int ans;
        ret a1,a2;
        a1.cnt=0;a2.cnt=0;
        if ((i==l)&&(i==r)){
            a1.cnt++;
            a1.b[a1.cnt]=nums[i];
            a2.cnt++;
            a2.b[a2.cnt]=nums[i+1];
        }
        else if (i==l)
            {a1.cnt++;
            a1.b[a1.cnt]=nums[i];
            a2=doit(i+1,r);}
        else if (i==r)
            {a2.cnt++;
            a2.b[a2.cnt]=nums[i+1];
            a1=doit(l,i-1);}
        else{
            a2=doit(i+1,r);
            a1=doit(l,i-1);
        }
        for (int k=1;k<=a1.cnt;k++)
            for (int j=1;j<=a2.cnt;j++){
                if (ope[i]=='+')
                    ans= a1.b[k]+a2.b[j];
                else if (ope[i]=='-')
                    ans= a1.b[k]-a2.b[j];
                else if (ope[i]=='*')
                    ans= a1.b[k]*a2.b[j];
                else if (ope[i]=='/')
                    ans= a1.b[k]/a2.b[j];    
                ans0.cnt++;
                ans0.b[ans0.cnt]=ans;
            //    cout<<ans<<' ';
            }
    }
    return ans0;
}


int main(){
    cin>>s;
    int tmp1=0;
    for (int i=0;i<s.size();i++){
        if ((s[i]>='0') && (s[i]<='9')){
            tmp1=tmp1*10+int(s[i])-48;
        }
        else{
            p1++;
            nums[p1]=tmp1;
            tmp1=0;
            p2++;
            ope[p2]=s[i];
        }
    }
    p1++;
    nums[p1]=tmp1;
    ret ans=doit(1,p2);
    sort(ans.b+1,ans.b+ans.cnt+1);
    for (int i=1;i<=ans.cnt;i++) cout<<ans.b[i]<<' ';
    cout<<'\n';
    // for (int i=1;i<=p1;i++) cout<<nums[i]<<' ';
    // cout<<'\n';
    // for (int i=1;i<=p2;i++) cout<<ope[i]<<' ';
    // cout<<'\n';
    return 0;
}