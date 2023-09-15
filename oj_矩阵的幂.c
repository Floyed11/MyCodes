#include <stdio.h>
int n,k;
int a[10][10],ans[10][10],ans0[10][10];

int main(){
    
    scanf("%d%d",&n,&k);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            {scanf("%d",&a[i][j]);ans[i][j]=a[i][j];}
    for (int i=2;i<=k;i++){
        for (int u=1;u<=n;u++)
            for (int v=1;v<=n;v++){
                int cnt=0;
                for (int w=1;w<=n;w++)
                    cnt+=ans[u][w]*a[w][v];
                ans0[u][v]=cnt;
            }
        for (int u=1;u<=n;u++)
            for (int v=1;v<=n;v++)
                ans[u][v]=ans0[u][v];
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<n;j++){
            printf("%d ",ans[i][j]);
        }
        printf("%d\n",ans[i][n]);
    }
    return 0;
}