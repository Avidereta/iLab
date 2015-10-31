#include <iostream>

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <malloc.h>
#include <stdlib.h>


const size_t max_size = 100;
// FYI: И правда же лучше, потому что он беззнаковый и именно для этого
// предназначен.
const size_t start_size = 100; // или лучше size_t?

typedef int stack_element; // для того, чтобы быстро изменять тип данных внутри

typedef struct stack
{
    size_t current_size;
    stack_element* data;
    int top;

};

int main() {

// FIXME: WHAAAT?
    stack* S
            {

            };
    size_t start_size = 5;
    void Stack_Init (stack* S, );

    return 0;
}
