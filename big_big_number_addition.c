#include<stdio.h>
#include<string.h>

void add(char a[], char b[], char res[]);

int main(){
    char a[100], b[100], res[105];
    scanf("%s %s", a, b);
    add(a, b, res);
    printf("%s", res);
    return 0;
}

// Your code goes here
void add(char a[], char b[], char res[]){
    char ca[100],cb[100],cres[105];
    int carry=0;
    //clean the array
    memset(ca,'\0',100);
    memset(cb,'\0',100);
    memset(res,'\0',105);
    memset(cres,'\0',105);
    int len=(strlen(a)>strlen(b))?strlen(a):strlen(b);
    if(strlen(a)>strlen(b)){
        for(int i=0;i<strlen(a)-strlen(b);++i)
            strcat(cb,"0");
    }else if(strlen(b)>strlen(a)){
        for(int i=0;i<strlen(b)-strlen(a);++i)
            strcat(ca,"0");
    }
    strcat(ca,a);
    strcat(cb,b);
    printf("%s",ca);
    printf("\n%s\n",cb);
    for(int i=0;i<len;++i){
        *(res+i)=(*(ca+len-i-1)-'0'+*(cb+len-i-1)-'0'+carry)%10+'0';
        carry=(*(ca+len-i-1)-'0'+*(cb+len-i-1)-'0'+carry)/10;
    }
    if(carry){
        strcat(res,"1");
    }
    for(int i=0;i<strlen(res);++i){
        *(cres+i)=*(res+strlen(res)-1-i);
    }
    strcpy(res,cres);
}
