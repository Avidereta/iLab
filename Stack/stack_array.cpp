#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "ErrorList.h"


#define $ ,


//Global constants should always be named UPPERCASE to show that they
// are global


typedef int stack_element;

typedef struct stack
{
    size_t current_size;
    stack_element* data;
    int top; //

} stack ;

// The goal of function IsOk is to return boolean value in order to
// allow programmer to call Dump after unsuccessfull result. Or assert(IsOk)
// if he don't want to diagnose the error.


bool IsOk (stack* S)
{
    if (!S)
        LOG_ERROR(false, "NULL pointer to stack, Dump is called");

    if (S->top >= (int)S->current_size)
        LOG_ERROR(false, "Top is out of current size, Dump is called");

    if (!(S->data))
        LOG_ERROR(false, "NULL pointer to stack data, Dump is called");

    return true;
}



int Dump(stack* S)
{

    if (!S)
        LOG_ERROR(NULL_STACK_POINTER, "NULL pointer to stack");

    LOG_PRINT_("Stack pointer %p", S);

    if (S->top >= (int)S->current_size)
        LOG_PRINT_("Top = %d, current_size = %zu\n", S->top $ S->current_size);

    if (!(S->data))
        LOG_ERROR(NULL_DATA_STACK_POINTER, "NULL pointer to stack data");

    for (int i = 0; i <= S->top; i++)
        LOG_PRINT_("Stack element number %d :%d ", i $ S->data[i]);

    return 0;
}


// Try to memorize our discussion about different kinds of errors.
// Lack of memory is a dynamic error, so it's incorrect to check this error
// with assert because assert will disappear in release version.

int StackInit (stack* S, size_t const start_size)
{
    stack_element* new_data = (stack_element *)calloc(start_size, sizeof(stack_element));

    if(!new_data)
        LOG_ERROR(CALLOC_ERROR, "NULL pointer in calloc");

    S->data = new_data;
    S->current_size = start_size;
    S->top = -1;
    if(!IsOk(S))
    {
        Dump(S);
        return DUMP_CALLED;
    }

    return 0;

}


void StackDestroy(stack* S)
{
    if(!IsOk(S))
        Dump(S);


    free(S->data);

    S->data = NULL;
    S->current_size = 0;
    S->top = -1;
}


bool IsEmpty (stack* S)
{
    if(!IsOk(S))
        Dump(S);


    if ((S->current_size == 0) || (S->top < 0))
        return true;

    return false;

}


// It's better to use enum in order to define errors and return
// value of proper error type.
// Check the pointer popped_element
int Pop(stack *S, stack_element* popped_element)
{
    if(!IsOk(S))
        return Dump(S), DUMP_CALLED;

    if (IsEmpty(S) == STACK_IS_EMPTY)
        return ERR_STACK_EMPTY;

    * popped_element = S->data[S->top];

    if (!(*popped_element)) return NULL_POINTER;

    S->data[S->top] = 0;
    S->top -= 1;

    if (S->top < (int) S->current_size / 4) {

        S->data = (stack_element *) realloc(S->data, S->current_size / 2);

        if (S->data) {
            S->current_size = S->current_size / 2;
            return 0;
        }

        return CALLOC_ERROR;
    }

    return 0;
}

int Remove(stack *S)
{
    if(!IsOk(S))
        return Dump(S), DUMP_CALLED;

    if (IsEmpty(S) == STACK_IS_EMPTY)
        return ERR_STACK_EMPTY;

    S->data[S->top] = 0;
    S->top -= 1;

    if (S->top < (int) S->current_size / 4) {

        S->data = (stack_element *) realloc(S->data, S->current_size / 2);

        if (S->data) {
            S->current_size = S->current_size / 2;
            return 0;
        }

        return CALLOC_ERROR;
    }

    return 0;
}

int Push (stack *S, stack_element new_element) {

    if(!IsOk(S))
        return Dump(S), DUMP_CALLED;

    if (S->top < (int)S->current_size)
    {
        S->data[++ S->top] = new_element;
        return 0;
    }

    S->data = (stack_element *) realloc(S->data, S->current_size * 2);

    if (S->data)
        return S->current_size = S->current_size * 2, 0;
    return CALLOC_ERROR;
}


int Add(stack* S)
{
    if(!IsOk(S))
        return Dump(S), DUMP_CALLED;

    stack_element a = 0;
    stack_element b = 0;
    Pop(S, &a);
    Pop(S, &b);

    stack_element sum = a + b;

    Push(S, sum);

    return 0;
}

int Subtraction(stack* S)
{
    if(!IsOk(S))
        return Dump(S), DUMP_CALLED;

    stack_element a = 0;
    stack_element b = 0;
    Pop(S, &a);
    Pop(S, &b);

    stack_element sub = a + b;

    Push(S, sub);

    return 0;
}


int Division(stack* S)
{
    if(!IsOk(S))
        return Dump(S), DUMP_CALLED;

    stack_element a = 0;
    stack_element b = 0;
    Pop(S, &a);
    Pop(S, &b);

    stack_element div = a/b;

    Push(S, div);

    return 0;
}

int Multiply(stack* S)
{
    if(!IsOk(S))
        return Dump(S), DUMP_CALLED;

    stack_element a = 0;
    stack_element b = 0;
    Pop(S, &a);
    Pop(S, &b);

    stack_element mult = a * b;

    Push(S, mult);

    return 0;
}