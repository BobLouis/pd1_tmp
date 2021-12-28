int addition(char str[]){
    char*p=str;
    int sum=0;
    char number[N];
    int i=0;
    while(*p!='\0') {
        i=0;
        while (*p != '+'&&*p!='\0') {
            number[i++] = *p;
            p++;
        }
        p++;
        number[i] = '\0';
        sum += atoi(number);
    }
    return sum;
}

