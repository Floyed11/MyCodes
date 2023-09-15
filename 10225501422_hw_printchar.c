#include<stdio.h>
int main(){
    int n;
    printf("please input the line: (1~26)");
    scanf("%d",&n);
    while (n > 26){
        printf("the number is too large\n");
        printf("please input the line: (1~26)");
        scanf("%d",&n);
    }
    int chr='A';
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n-i;j++) printf(" ");
        for (int j=1;j<=2*i-1;j++) printf("%c",chr);
        chr++;
        printf("\n");
    }
    return 0;
}