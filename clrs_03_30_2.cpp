#include<iostream>
#include<string>
using namespace std;

string doit(string s){
    int p=0,len=s.size();
    char i;
    string re_s="";
    while(p<len){
        i = s[p];
        int cnt=1;
        while(s[p+1]==i){
            p++;
            cnt++;
        }
        re_s=re_s+char(cnt+48)+i;
        p++;
    }
    return re_s;
}

string countAndSay(int x){
    if (x==1) return "1";
    else return (doit(countAndSay(x-1)));
}

int main(){
    int n;
    cin>>n;
    cout<<countAndSay(n)<<'\n';
    return 0;
}