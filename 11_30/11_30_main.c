#include<stdio.h>
#include<math.h>
#include<stdlib.h>

extern int points;
int center;
extern int x[100];
extern int y[100];

int doit(int x[],int y[],int points){
    int min_cnt=1;
    double min_sum=-1;
    for (int i=1;i<=points;i++){
         double sum=0;
        for (int j=1;j<=points;j++){
            sum+=sqrt(pow((x[j]-x[i]),2)+pow((y[j]-y[i]),2));
        }
        if (min_sum==-1 || sum < min_sum){
            min_sum=sum;
            min_cnt=i;
        }
    }
    return min_cnt;
}

int main(){
    
    printf("finding...\n");
    center=doit(x,y,points);
    printf("the center point is (%d, %d)\n",x[center],y[center]);
    printf("%d\n",points);
    return 0;
}