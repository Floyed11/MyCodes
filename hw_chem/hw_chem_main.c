#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double *Normalization(int *array,int len,int par){
    double std_deviation,sum=0,max=array[0],min=array[0],average=0;
    double *ans=(double *)malloc(30 * sizeof(double));
    for (int i=0;i<len;i++){
        if (array[i]>max) max=array[i];
        if (array[i]<min) min=array[i];
        sum+=array[i];
    }
    average=sum / len;
    // for (int i=0;i<len;i++)
    //     printf("%d ",array[i]);
    if (par==1){
        for (int i=0;i<len;i++){
            ans[i]=(array[i]-average) / (max-min);
            // printf("%llf ",ans[i]);
        }
    }
    else if (par==2){
        double temp=0;
        for (int i=0;i<len;i++){
            temp+=pow(array[i]-average,2);
        }
        std_deviation=sqrt(temp / len);
        for (int i=0;i<len;i++)
            ans[i]=(array[i]-average) / std_deviation;
    }
    // for (int i=0;i<len;i++)
    //     printf("%llf ",ans[i]);
    return ans;
}

int main(){

    double *answer=NULL;
    int len=24,par;
    extern int data[];
    printf("par=");
    scanf("%d",&par);
    answer=Normalization(data,len,par);
    printf("[%.16llf",answer[0]);
    for (int i=1;i<len;i++)
        printf(",%.16llf",answer[i]);
    printf("]\n");
    free(answer);
 //   printf("%d",sizeof(data)/sizeof(int));
    return 0;

}