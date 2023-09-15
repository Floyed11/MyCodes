#include <stdio.h>
#include <string.h>

int main(){

    int day[20]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    char idcode[100]={0};
    int y,m,d,cou=0;
    printf("Input your ID: ");
    gets(idcode);
    for (int i=6;i<=13;i++){
        cou=cou * 10 + idcode[i] - '0';
    }
    y = cou / 10000;
    m = cou / 100 % 100;
    d = cou % 100;
    int num = d;
    if ((y % 400 == 0)||((y % 4 == 0)&&(y % 100 != 0))) day[2]=29;
    for (int i=1;i<m;i++) num+=day[i];
    printf("It's the %d day of the year. ",num);
    return 0;

}