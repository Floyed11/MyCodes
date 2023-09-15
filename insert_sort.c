#include<stdio.h>

void insert_sort(int a[],int n){
    for(int i=1;i<n;i++){
        int min_index=i-1;
        int temp=a[i];
        while (min_index>=0)
        {
            if (a[min_index]>temp){
                a[min_index+1]=a[min_index];
                min_index--;
            }
            else{
                break;
            }
        }
        a[min_index+1]=temp;
    }
}

int main(){
    int a[]={12,2,16,-8,3};
    int n=5;
    insert_sort(a,n);
    for (int i=0;i<n;i++)
        printf("%d ",a[i]);
    return 0;
}