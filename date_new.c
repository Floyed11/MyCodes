#include <stdio.h>
#define size 13
int main(){
    
    int day[size]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    int y,m,d;
    int count=0;
    printf("input year: ");
    scanf("%d",&y);
    printf("input month: ");
    scanf("%d",&m);
    printf("input day: ");
    scanf("%d",&d);
    if ((y % 400 == 0)||((y % 4 == 0)&&(y % 100 != 0))) day[2]=29;
    for (int i=1;i<m;i++) count+=day[i];
    count+=d;
    printf("It's the %d day of the year. ",count);
    return 0;

}