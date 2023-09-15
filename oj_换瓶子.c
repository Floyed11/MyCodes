#include <stdio.h>

int doit(int n){
    if (n ==2){
        return 1;
    }
    else if (n == 1){
        return 0;
    }
    return (n / 3 + doit(n % 3 + n / 3));
}

int main(){
    int n;
    scanf("%d",&n);
    while (n!=0){
        printf("%d\n",doit(n));
        scanf("%d",&n);
    }
    return 0;
}