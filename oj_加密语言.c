#include<stdio.h>
#include<string.h>
int main(){
    char s[60],t[60],alter_str[60];
    scanf("%s%s",s,t);
/*   if (strlen(s)>strlen(t)){
        char tmp[60];
        strcpy(tmp,s);
        strcpy(s,t);
        strcpy(t,tmp);
    }
*/
    int minlen=strlen(s);
    if (strlen(t)<minlen) minlen=strlen(t);
    for (int i=1;i<=minlen;i++){
        alter_str[(i-1)*2]=s[i-1];
        alter_str[i*2-1]=t[i-1];
    }
    if (strlen(s)>strlen(t)){
        char tmp[60];
        strcpy(tmp,s);
        strcpy(s,t);
        strcpy(t,tmp);
    }
    for (int i=strlen(s);i<strlen(t);i++){
        alter_str[strlen(s)*2+i-strlen(s)]=t[i];
    }
    alter_str[strlen(s)+strlen(t)]='\0';
    printf("%s\n",alter_str);
    return 0;
}