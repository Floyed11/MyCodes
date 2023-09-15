#include<stdio.h>
#include<math.h>

int x[1000],y[1000];
int points=0,center=1;

int len_sum(int k){
    int sum=0;
    for (int i=1;i<=points;i++){
        sum+=sqrt(pow((x[k]-x[i]),2)+pow((y[k]-y[i]),2));
    }
    return sum;
}

int main(){
    printf("please input the points: ");
    scanf("%d",&points);
    printf("please input the pointX: ");
    for (int i=1;i<=points;i++){
        scanf("%d",&x[i]);
    }
    printf("please input the pointY: ");
    for (int i=1;i<=points;i++){
        scanf("%d",&y[i]);
    }
    printf("finding...\n");
    for (int i=2;i<=points;i++){
        if (len_sum(center)>len_sum(i))
            center = i;
    }
    printf("the center point is (%d, %d)\n",x[center],y[center]);
    return 0;
}