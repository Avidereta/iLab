
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
    int b = 10;
    int c = 15;
    printf("\nTest push: \n");
    Push(&S, a);
    Push(&S,b);
    Push(&S,c);
    Push(&S,b);
    Push(&S,a);
    Push(&S,a);
    Dump(&S);

    stack_element popped_element = 0;
    printf("\nTest pop: \n");
    Pop(&S, &popped_element);
    printf( "popped element %d \n", popped_element);
    Dump(&S);

    printf("\nTest add: \n");
    Add(&S);
    Dump(&S);

    printf("\nTest multiply: \n");
    Multiply(&S);
    Dump(&S);

    printf("Test substraction: \n");
    Subtraction(&S);
    Dump(&S);

    printf("\nTest division: \n");
    Division(&S);
    Dump(&S);

    printf("\nTest remove element \n");
    Remove(&S);
    Dump(&S);

    printf("\nTest StackDestroy: \n");
    StackDestroy(&S);
    Dump(&S);

 return 0;
}