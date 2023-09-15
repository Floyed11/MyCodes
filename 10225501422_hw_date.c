#include <stdio.h>

int main(){
    int d,m,y;
    int num = 0;
    printf("input year:");
    scanf("%d",&y);
    printf("input month:");
    scanf("%d",&m);
    printf("input date:");
    scanf("%d",&d);
    int flag_leap;
    if(m>2) flag_leap=y % 400==0 ||((y % 4==0) && (y % 100 !=0));
    int m0=m-1; num=d;
    num+=31 * m0 - (m0>=2)*3 - (m0>=4) - (m0>=6) - (m0>=9) - (m0>=11) + flag_leap;
    printf("The date you input : %d-%d-%d is the %d day of the year",y,m,d,num);
    return 0;
}