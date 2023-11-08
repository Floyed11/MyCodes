#include<stdio.h>

int doit(int x, int y, int z){
    int temp;
    temp = y + (z - y) / 2;
    if (temp > x){
        return temp + doit(x, y, temp - 1);
    }
    else if (temp < x){
        return temp + doit(x, temp + 1, z);
    }
    else{
        return temp;
    }
}

int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    doit(a,0,14);
}