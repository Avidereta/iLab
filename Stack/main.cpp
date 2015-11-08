
#include <stdio.h>
#include <assert.h>
#include "Stack.h"
//#include "stack_array.cpp"


int main() {

    size_t const start_size = 10;
    stack S = {};

    printf("start_size: %zu \n", start_size);
    //printf ("S hello %p \n", S);
    //printf("%zu \n", start_size);
    int u = StackInit (&S, start_size);
    //printf("%zu \n", start_size);
    //int line = Dump(&S);
    //printf ("S after %p \n", &S);
    int a = 5;
    int b = 5;
    int i = Push(&S, a);
    printf("start_size: %zu \n", start_size);
    i = Push(&S,b);
    Dump(&S);




    return 0;
}