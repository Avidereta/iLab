#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <stdlib.h>

//Global constants should always be named UPPERCASE to show that they
// are global

enum MISTAKES

{
    ERR_STACK_EMPTY = 1,
    STACK_IS_EMPTY =  2,
    CALLOC_ERROR = 3,
    DUMP_CALLED = 4
}

const size_t start_size = 100;
typedef int stack_element;


typedef struct stack
{
    size_t current_size;
    stack_element* data;
    int top; //

};


// The goal of function IsOk is to return boolean value in order to
// allow programmer to call Dump after unseccesfull result. Or assert(IsOk)
// if he don't want to diagnose the error.

bool IsOk (stack* S)
{
    if (!S) return false;
    if (S->top >= S->current_size) return false;
    if (!(S->data)) return false;
    else return true;
}
# define $ ,
#define LOG_PRINT(fmt, value) printf(fmt, value)

int Dump(stack* S)
{
    if (!S) LOG_PRINT("error: NULL pointer to stack. Stack pointer = %d\n", S);
    if (S->top >= S->current_size) LOG_PRINT("error: top is out of current size. Top = %d, current_size = %d\n", (S->top $ S->current_size));
    if (!(S->data)) LOG_PRINT("error: NULL pointer to stack data. Data pointer = %d\n", S->data);
    for (int i = 0; i < S->top; i++)
    {
        LOG_PRINT("Stack element number %d :%d \n", (i $ S->data[i]));
    }

    return __LINE_;
}



int StackInit (stack* S, size_t start_size)
{
    if(!IsOk(S))
        return (Dump(S)), DUMP_CALLED;
    else
    {
        stack_element* new_data = NULL;  //  0 is for numbers, NULL for pointers
        new_data = (stack_element *)calloc(start_size, sizeof(stack_element));

// Try to memorize our discussion about different kinds of errors.
// Lack of memory is a dynamic error, so it's incorrect to check this error
// with assert because assert will disappear in release version.
        if(!new_data) return CALLOC_ERROR;
        else {
            S->data = new_data;
            S->current_size = start_size;
            //S->top = (stack_element *)(-1);
            S->top = -1;
            return 0;
        }
    }
}


void StackDestroy(stack* S)
{
    if(!IsOk(S))
        Dump(S);

    else {
        free(S->data);

        S->data = NULL;
        S->current_size = 0;
        S->top = -1;
        //S->top = (stack_element *)(-1);
    }

}


bool IsEmpty (stack* S)
{
    if(!IsOk(S))
        Dump(S);

    else {

        if ((S->current_size == 0) || (S->top < 0))
            return 1;

        else
            return 0;
    }
}


// It's better to use enum in order to define errors and return
// value of proper error type.
// Check the pointer popped_element
int Pop(stack *S, stack_element* popped_element)
{
    if(!IsOk(S))
        return (Dump(S)), DUMP_CALLED;

    else {

        if (IsEmpty(S) == STACK_IS_EMPTY)
            return ERR_STACK_EMPTY;
            // What this function will return in other cases?

            // Why do you need else? You already have return.
        else {
            *popped_element = S->data[S->top];
            assert(popped_element);
            S->data[S->top] = 0;
            S->top -= 1;
            if (S->top < S->current_size / 4) {

                S->data = (stack_element *) realloc(S->data, S->current_size / 2);
                if (S->data) {
                    S->current_size = S->current_size / 2;
                    return 0;
                }
                else return CALLOC_ERROR;
            }
            return 0;
        }

    }



}

int Push (stack *S, stack_element new_element) {
    // Check pointers!
    if(!IsOk(S))
        return (Dump(S)), DUMP_CALLED;

    else {

        if (S->top < S->current_size)
        {
            S->data[S->top++] = new_element;
            return 0;

        }
        else {
            S->data = (stack_element *) realloc(S->data, S->current_size * 2);
            if (S->data)
                return (S->current_size = S->current_size * 2), 0;
            else return CALLOC_ERROR;
        }
    }
}