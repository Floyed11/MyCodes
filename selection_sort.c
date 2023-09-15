#include<stdio.h>

void selection_sort(int a[],int n){
    for(int i=0;i<n-1;i++){
        int min=i;
        int flag=1;
        for(int j=i+1;j<n;j++){
            if (a[min]>a[j])
                min=j;
            if (a[j-1]>a[j])
                flag=0;
        }
        if (flag)
            break;
        int temp=a[i];
        a[i]=a[min];
        a[min]=temp;
    }
    return;
}

void recursion_selection_sort(int a[],int n,int m){
    if (m==n-1)
        return;
    int min=m;
    for (int i=m+1;i<n;i++){
        if (a[min]>a[i])
            min=i;
    }
    int temp=a[m];
    a[m]=a[min];
    a[min]=temp;
    recursion_selection_sort(a,n,m+1);
}

int main(){
    int a[]={12,2,16,-8,3};
    int n=5;
    recursion_selection_sort(a,n,0);
    for (int i=0;i<n;i++)
        printf("%d ",a[i]);
    return 0;
}