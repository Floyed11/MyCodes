#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp(const void* _a , const void* _b)
{
    int* a = (int*)_a;
    int* b = (int*)_b;
    return *a - *b;
}
int comp(const void *x,const void *y)
{
	char *w=*(char**)x;
	char *q=*(char**)y;
	return strcmp(w,q);
}
int main(){
    int n,m,k;
    char s[205][14],s0[205][14];
    int a[205],b[205];
    int a0[205],b0[205];
    scanf("%d%d%d",&n,&m,&k);
    for (int i=0;i<n;i++){
        scanf("%s%d%d",s[i],&a[i],&b[i]);
        a0[i]=a[i];b0[i]=b[i];
    }
    qsort(a,n,sizeof(int),cmp);
    qsort(b,n,sizeof(int),cmp);
    int p=0;
    for(int i=0;i<n;i++){
        if(a0[i]>=a[n-m]&&b0[i]>=b[n-k]){
            strcpy(s0[p],s[i]);
            p++;
        }
    }
    for (int i=1;i<=p;i++)
        for (int j=0;j<p-i;j++)
            if (strcmp(s0[j],s0[j+1])>0){
                char tmp[14];
                strcpy(tmp,s0[j]);
                strcpy(s0[j],s0[j+1]);
                strcpy(s0[j+1],tmp);
            }
    for (int i=0;i<p;i++)printf("%s\n",s0[i]);
    return 0;
}