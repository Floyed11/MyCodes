#include<stdio.h>
#include<stdlib.h>

int total=0;
long long *a;

long long Fib(int n){
    total++;
    if (n==1)
        return 0;
    if (n==2)
        return 1;
    if (a[n-1]<=0)
        a[n-1]=Fib(n-1);
    if (a[n-2]<=0)
        a[n-2]=Fib(n-2);
    return(a[n-1]+a[n-2]);
}

int main(){
    int n;
    printf("please input a number: ");
    scanf("%d",&n);
    a=(long long *)malloc((n+5)*sizeof(long long));
    for (int i=1;i<=n;i++)
        a[i]=-1;
    a[1]=0;a[2]=1;
    a[n]=Fib(n);
    for (int i=1;i<=n;i++) printf("%lld ",a[i]);
    printf("\n%d\n",total);
    free(a);
    return 0;
}