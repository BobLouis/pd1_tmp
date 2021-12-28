#include<stdio.h>
long long int C(int n,int m);
int main(){
     int n,m;
    scanf("%d%d",&n,&m);
    printf("%lld",C(n,m));
    return 0;
}
long long int C(int n,int m){
    if(n==m||m==0){
        return 1;
    }else {
        return C(n-1,m-1)+C(n-1,m);
    }
}

