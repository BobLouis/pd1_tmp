#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(char* a, char* b){
    return strcmp(a,b);
}
void recur(char* arr,int len,int total){
    char val[10];
    char origin[10];
    strcpy(origin,arr);
    memset(val,'\0',6);
    char tmp;
    if(len==2){
        printf("%s\n",arr);
        tmp=*(arr+total-2);
        *(arr+total-2)=*(arr+total-1);
        *(arr+total-1)=tmp;
        printf("%s\n",arr);
        return;
    }

    for(int i=0;i<len;++i){
        memset(val,'\0',10);
        *val = *(arr + i);
        *(arr + i) = '\0';
        strcat(val, arr);
        strcat(val, arr + i + 1);
//        printf("%s\n", val);
        strcpy(arr,origin);
        recur(val,len-1,total);
    }

//        recur(val,len-1,total);


}
    int main() {
    char str[10];
    scanf("%s",str);
    qsort(str,strlen(str),sizeof(char),cmp);
//    printf("%s\n\n",str);
    int length=strlen(str);
//    printf("%d",length);
//    printf("\n");
    recur(str,length,length);
    return 0;
}

