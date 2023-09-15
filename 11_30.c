#include<stdio.h>
#include<math.h>
#include<stdlib.h>

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
    int points,center;
    printf("please input the points: ");
    scanf("%d",&points);
    int *x=(int *)malloc(points * sizeof(int));
    int *y=(int *)malloc(points * sizeof(int));
    printf("please input the pointX: ");
    for (int i=1;i<=points;i++){
        scanf("%d",&x[i]);
    }
    printf("please input the pointY: ");
    for (int i=1;i<=points;i++){
        scanf("%d",&y[i]);
    }
    printf("finding...\n");
    center=doit(x,y,points);
    printf("the center point is (%d, %d)\n",x[center],y[center]);
    free(x);
    free(y);
    return 0;
}
