#include <stdio.h>
#include <stdlib.h>
#define n 8000

// Ignore this
void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*)){exit(1);}
// Ignore this

void quicksort(int a[], int low, int high);
int main(void) {
    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    quicksort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}

// Your code goes here
int split(int *a,int low,int high){
    int pivot=*(a+low);  //let pivot be the first element
    while(1){
        while(low<high&&*(a+high)>=pivot)
            high--;
        if(low>=high)
            break;
        *(a+low++)=*(a+high);

        while(low<high&&*(a+low)<=pivot)
            low++;
        if(low>=high)
            break;
        *(a+high--)=*(a+low);
    }
    *(a+high)=pivot;
    return high;
}

void quicksort(int *a, int low, int high) {
    if(low>=high)
        return;
    int middle=split(a,low,high);
    //sort low

    quicksort(a,low,middle-1);
    //sort high
    quicksort(a,middle+1,high);
}
//low point to the first element high point to the last element

