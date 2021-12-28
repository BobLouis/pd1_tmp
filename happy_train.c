#include <stdio.h>
#include <stdlib.h>

struct Car{
    int passenger;
    int flammable;
    struct Car*next;
};

void attachCar(struct Car *head,int passenger,int flammable){
    struct Car *curr=head;
    while(curr->next)
        curr=curr->next;
    struct Car *newCar=malloc(sizeof(struct Car));
    newCar->passenger=passenger;
    newCar->flammable=flammable;
    newCar->next=NULL;
    curr->next=newCar;
}
int fire(struct Car*);

int main(int argc,char *argv[]){
    int car;
    int human[13],moeru[13];
    struct Car head;
    head.next=NULL;
    scanf("%d",&car);
    for(int i=0;i<car;++i)
        scanf("%d",(human+i));
    for(int i=0;i<car;++i)
        scanf("%d",(moeru+i));
    for(int i=0;i<car;++i)
        attachCar(&head,*(human+i),*(moeru+i));
    printf("%d",fire(&head));
}

int fire(struct Car *head){
    int people=0;
    int flammable=0;
    int sum=0;
    struct Car *p= head;
    while(1){
        p=p->next;
        people+=p->passenger;
        if(people>=p->flammable)
            break;
        sum++;
        if(p->next==NULL)
            break;
    }
    return sum;
}
