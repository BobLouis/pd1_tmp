#include <stdio.h>
#include <stdlib.h>
#define max 50
struct mat{
    int row;
    int col;
    int value[max][max];
};

void scan_mat(struct mat *);
void print_mat(const struct mat *);
void add_mat(const struct mat *, const struct mat *, struct mat *);
void mul_mat(const struct mat *, const struct mat *, struct mat *);



int main(){
    struct mat m1,m2,result;
    char op;
    scan_mat(&m1);
    getchar();
    scanf("%c",&op);
    getchar();
    scan_mat(&m2);
    switch(op){

        case '+':
            add_mat(&m1,&m2,&result);
            break;
        case '*':
            mul_mat(&m1,&m2,&result);
            break;
    }
    print_mat(&result);
    return 0;
}

void scan_mat(struct mat *m_p){
    int row,col;
    scanf("%d%d",&row,&col);
    m_p->row=row;
    m_p->col=col;
    for(int i=0;i<row;++i){
        for(int j=0;j<col;++j){
            scanf("%d",&m_p->value[i][j]);
        }
    }
}
void print_mat(const struct mat*m_p){

    for(int i=0;i<m_p->row;++i){
        for(int j=0;j<m_p->col;++j){
            printf("%d ",m_p->value[i][j]);
        }
        printf("\n");
    }
}

void add_mat(const struct mat*m1_p,const struct mat *m2_p,struct mat *res_p){
    res_p->row=m1_p->row;
    res_p->col=m1_p->col;
    for(int i=0;i<m1_p->row;++i){
        for(int j=0;j<m2_p->col;++j)
            res_p->value[i][j]=m1_p->value[i][j]+m2_p->value[i][j];
    }
}

void mul_mat(const struct mat *m1_p,const struct mat *m2_p,struct mat *res_p){
    res_p->row=m1_p->row;
    res_p->col=m2_p->col;
    int sum=0;
    for(int i=0;i<res_p->row;++i){
        for(int j=0;j<res_p->col;++j){
            sum=0;
            for(int k=0;k<m1_p->col;++k){

                sum+=(m1_p->value[i][k])*(m2_p->value[k][j]);
            }
            res_p->value[i][j]=sum;
        }
    }
}


