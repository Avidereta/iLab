
#include <stdio.h>
#include <assert.h>
//#include "Stack.h"
#include "stack_array.cpp"


int main() {

    size_t start_size = 5;
    stack S = {};
    StackInit (&S, start_size);
    int a = 5;
    int b = 5;
    Push(&S, a);
    Push(&S,b);
    Dump(&S);



    return 0;
}