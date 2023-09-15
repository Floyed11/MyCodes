#include <stdio.h>
#include <string.h>
#define size 100000

int main(){

    char key[size];
    int k;
    char ori_key[size];
    printf("Please input the k(<20): \n");
    scanf("%d",&k);
    printf("Please input the encoded string(only include a~z A~Z): \n");
    scanf("%s",key);
    int len = strlen(key);
    for (int i=0;i<len;i++){
        char c=key[i],cou;
        if ((c>='0') && (c<='9')){
            ori_key[i]=c;
            continue;
        }
        if ((c>='A') &&(c<='Z')){
            c=c-'A'+'a';
            cou='a';
        } 
        else {
                c=c-'a'+'A';
                cou='A';
        }
        ori_key[i]=(char)(c-cou-k+26)%26+cou;
    }
    printf("original string: %s\n",ori_key);
    return 0;

}