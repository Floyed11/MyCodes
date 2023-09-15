#include<stdio.h>

char search(int x,int a[],int n,int m,int tmp,int l){
    if(x>n)
        if(tmp==0)
            return 'C';
        else if(tmp==1)
            return 'A';
        else if(tmp==2) return 'B';
    int p=1;
    while(a[(x-1)*m+p]==0 && p<=m) p++;
    while(a[(x-1)*m+p]==1 && p<=m) p++;
    int p0=p;
    while(a[(x-1)*m+p]==0 && p<=m) p++;
    int p1=p-1;
    if (p>m) 
        if (l==0)return search(x+1,a,n,m,tmp,0);
        else if (tmp!=0)return search(x+1,a,n,m,tmp-1,0);
        else return search(x+1,a,n,m,tmp,0);
    int flag=1;
    for (int i=p0;i<=p1;i++){
        if (a[x*m+i]==0)
            flag=0;
    }
    if (flag==1){
        return search(x+2,a,n,m,tmp+1,0);
    }
    else
        return search(x+1,a,n,m,tmp,1);
}

int main(){
    int t,n,m;
    scanf("%d",&t);
    fflush(stdin);
    for(int i=1;i<=t;i++){
        scanf("%d%d",&n,&m);
        fflush(stdin);
        int k[2505];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                char c=getchar();
                k[(i-1)*m+j]=c-'0';
                }
            getchar();
        }
        printf("%c\n",search(1,k,n,m,0,0));
    }
    return 0;
}