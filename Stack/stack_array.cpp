#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <stdlib.h>

// FIXME: Global constants should always be named UPPERCASE to show that they
// are global
#define err_stack_empty 4
#define stack_is_empty 1
#define stack_is_not_empty


const size_t start_size = 100;
typedef int stack_element;


typedef struct stack
{
    size_t current_size;
    stack_element* data;
    int top; //

};


// FIXME: THe goal of function IsOk is to return boolean value in order to
// allow programmer to call Dump after unseccesfull result. Or assert(IsOk)
// if he don't want to diagnose the error.
void IsOk (stack* S)
{
    assert(S);
    assert(S->top < S->current_size);
    assert(S->data);
}

// FIXME: What's strange name? Either CamelCase or snake_case.
void Stack_Init (stack* S, size_t start_size)
{
    IsOk(S);
    stack_element* new_data = 0; // FIXME: 0 is for numbers, NULL for pointers

    new_data = (stack_element *)calloc(start_size, sizeof(stack_element));

// FIXME: Try to memorize our discussion about different kinds of errors.
// Lack of memory is a dynamic error, so it's incorrect to check this error
// with assert because assert will disappear in release version.
    assert(new_data);

    S->data = new_data;
    S->current_size = start_size;
    //S->top = (stack_element *)(-1);
    S->top = -1;
}


void StackDestroy(stack* S)
{
    IsOk(S);

    free(S->data);

    S->data = NULL;
    S->current_size = 0;
    S->top = -1;
    //S->top = (stack_element *)(-1);

}

// FIXME: Why the function is not boolean?
int IsEmpty (stack* S)
{
    IsOk(S);

    if ((S->current_size == 0) || (S->top < 0))
        return 1;

    else
        return 0;
}


// FIXME: It's better to use enum in order to define errors and return
// value of proper error type.
// FIXME: Check the pointer popped_element
int Pop(stack *S, stack_element* popped_element)
{
    IsOk(S);

    if (IsEmpty(S) == stack_is_empty)
        return err_stack_empty;
    // FIXME: What this function will return in other cases?

    // FIXME: Why do you need else? You already have return.
    else {
        *popped_element = S->data[S->top];
        S->data[S->top] = 0;
        S->top = S->top - 1; // FYI: -= 1?

    }

    if (S->top < S->current_size/4)
    {
        // FIXME: How about changing the current_size as well?
        S->data = (stack_element *)realloc(S->data, S->current_size / 2);
    }

}

void Push (stack *S, stack_element new_element)
{
    // FIXME: Check pointers!
    IsOk(S);

    if (S->top < S->current_size)
    {
        S->data[S -> top ++] = new_element;
        S->top ++;
        // FIXME: top +=2. Really?
    }
    else
    {
        S->data = (stack_element *)realloc(S->data, S->current_size * 2);
        S->current_size = S->current_size * 2;
    }


}
