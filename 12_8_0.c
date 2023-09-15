#include <stdio.h>

int Fib (int n){
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;
    return (Fib(n-1)+Fib(n-2));
}

int main(){
    int n;
    printf("please input n: ");
    scanf("%d",&n);
    for (int i=1;i<=n;i++) printf("%d ",Fib(i));
    return 0 ;
}