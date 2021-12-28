#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int rising_hope(char *R);

int main(int argc, char *argv[])
{
    char in[1005];

    scanf("%s", in);
    int hope = rising_hope(in);
    printf("%d\n", hope);

    return 0;
}
int rising_hope(char *R) {
    int val=0;
    while(*R != 0){
        if(*R=='P')
            val++;
        else if(*R=='N')
            val--;
        R++;
    }
    return val;
}

