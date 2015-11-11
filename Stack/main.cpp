
#include <stdio.h>
#include <assert.h>
#include "Stack.h"
//#include "stack_array.cpp"


int main() {

    size_t const start_size = 10;
    stack S = {};

    printf("start_size: %zu \n", start_size);

    StackInit (&S, start_size);

    int a = 5;
    int b = 5;
    int c = 15;
    Push(&S, a);
    Push(&S,b);
    Push(&S,c);
    Push(&S,b);
    Dump(&S);

    stack_element popped_element = 0;
    Pop(&S, &popped_element);
    printf( "\npopped el %d \n", popped_element);
    Dump(&S);

    Add(&S);
    Dump(&S);
    Multiply(&S);
    Dump(&S);






    return 0;
}