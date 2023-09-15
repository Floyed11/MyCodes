#include <stdio.h>

long long getnum(int n){
    if (n==1)
        return 3;
    if (n==2)
        return 8;
    return 2*getnum(n-1)+2*getnum(n-2);
}
int main(){
    int n;
    printf("please input n: ");
    scanf("%d",&n);
    printf("%lld",getnum(n));
    return 0;
}