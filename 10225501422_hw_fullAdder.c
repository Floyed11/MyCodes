#include<stdio.h>

int main(){

    int a0=1,a1=1,b0=1,b1=1,c0,c1,s0,s1,s2=0;
    c0 = a0 & b0;
    s0 = a0 ^ b0;
    s1 = c0 ^ a1 ^ b1;
    c1 = (c0 & a1)|(c0 ^ a1 & b1);
    s2 = c1;
    printf("%d%d+%d%d=%d%d%d",a1,a0,b1,b0,s2,s1,s0);
    return 0;
    
}