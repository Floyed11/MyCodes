#include<stdio.h>
#include<math.h>

int n,p[11];

int main(){

    int ans=0,digit=0,flag=0;
    scanf("%d",&n);
    int n0=n;
    while (n0 > 0)
    {
        digit++;
        n0 /= 10;
    }
    for (int i=0;i<=9;i++){
        p[i] = pow (i,digit);
    }

    int n1=n ,sum=0;
    while(n1>0){
        int m = n1 % 10;
        n1=n1 / 10;
        sum += p[m];
    }
    if (sum==n) flag = 1;

    if (flag)
        printf("%d is a narcissistic number",n);
    else 
        printf("%d is not a narcissistic number",n);
    return 0;

}