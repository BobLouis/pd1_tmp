#include <stdio.h>
#include <string.h>
#define N 10
typedef struct dict_t_struct{
    char word[10];
    int page;
} dict_t;

int search (dict_t *array,char* target);

int main(){
    dict_t dictionary[N];
    char target[N];
    int target_page;
    for(int i=0;i<N;++i)
        scanf("%s %d\n",dictionary[i].word,&dictionary[i].page);
    scanf("%s",target);
    target_page=search(dictionary,target);
    printf("%d",target_page);
    return 0;
}

int search(dict_t *dictionary,char *target){
    for(int i=0;i<N;++i){
        if(strcmp(dictionary[i].word,target)==0){
            return dictionary[i].page;
        }
    }
    return 0;
}
