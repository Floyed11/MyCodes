#include <stdio.h>
#include <math.h>

int isprime(int x){
    for (int i=2;i<=sqrt(x);i++)
        if (x % i==0) return 0;
    return 1;
}
int main(){
    int x,flag=0;
    printf("please input a number: ");
    scanf("%d",&x);
    for (int i=2;i<=x/2;i++){
        if (isprime(i) && isprime(x-i)){
            printf("%d = %d + %d\n",x,i,x-i);
            flag=1;
        }
    }
    if (flag==0) printf("not found\n");
    return 0;
}