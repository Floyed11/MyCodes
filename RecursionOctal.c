#include<stdio.h>

int trans(int num){
    if (num<=0)
        return 0;
    return (trans(num / 8)*10+num % 8);
}

int main(){
    int n;
    printf("please input a decimal number: ");
    scanf("%d",&n);
    printf("after transform: %d\n",trans(n));
    printf("%o\n",n);
    return 0;
}