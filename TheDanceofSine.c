#include<stdio.h>
#include<string.h>

char *A(int i,int n){
    char *chr;
    itoa(n,chr,10);
    if (i==n) return "sin(n)";
    char *tmp=strcat("sin(",chr);
    tmp=strcat(tmp,")");
    if (n % 2==0){
        chr="+";
    }
    else{
        chr="-";
    }
    tmp=strcat(tmp,chr);
    tmp=strcat(tmp,A(i+1,n));
    return strcat(tmp,")");
}

// char *S(int n){

// }

int main(){
    int n;
    scanf("%d",&n);
    printf("%s\n",A(1,n));
    return 0;
}