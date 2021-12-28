#include <stdio.h>
#include <stdlib.h>

int main(){
    int n,m,tmp;
    scanf("%d%d",&n,&m);
    int *p=malloc(sizeof(int)*n);
    for(int i=0;i<n;++i){
        *(p+i)=i+1;
    }
//    printf("m=%d",m);
    for(int i=0;i<m;i++){
        printf("%d ",*p);
//        printf("i=%d",i);
        tmp=*(p+1);
        for(int j=0;j<n-2-i;++j){
            *(p+j)=*(p+j+2);
        }
        *(p+n-2-i)=tmp;
    }

    return 0;
}
