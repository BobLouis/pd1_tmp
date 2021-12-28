#include <stdio.h>

int func(int n,int m){
    if(!n){
        return m+1;
    }else if(!m){
        return func(n-1,1);
    }else{
        return func(n-1,func(n,m-1));
    }
}
int main(void){
    int n,m;
    scanf("%d%d",&n,&m);
    printf("%d",func(n,m));
    return 0;
}

