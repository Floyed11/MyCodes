#include<stdio.h>
#include<math.h>
int flag[100005];

int judge(int x){
    if (flag[x]!=0)
        return 1;
    if (x==0||x==1)
        return 0;
    else{
        flag[x]=1;
        for (int i=2;i<x;i++){
        if (x % i==0){
            flag[x]=0;
            break;
            }
        }
        return flag[x];
    }
}
    

int main(){
    for (int i=0;i<=100000;i++)flag[i]=0;
    int n,a[200005];
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int count=0;
    for (int i=1;i<=n;i++){
        if (judge(a[i])==1)
            count+=1;
    }
    printf("%d\n",count);
    return 0;
}