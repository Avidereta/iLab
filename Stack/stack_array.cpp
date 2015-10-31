#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <stdlib.h>

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


void IsOk (stack* S)
{
    assert(S);
    assert(S->top < S->current_size);
    assert(S->data);
}


void Stack_Init (stack* S, size_t start_size)
{
    IsOk(S);
    stack_element* new_data = 0;

    new_data = (stack_element *)calloc(start_size, sizeof(stack_element));

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

int IsEmpty (stack* S)
{
    IsOk(S);

    if ((S->current_size == 0) || (S->top < 0))
        return 1;

    else
        return 0;
}


int Pop(stack *S, stack_element* popped_element)
{
    IsOk(S);

    if (IsEmpty(S) == stack_is_empty)
        return err_stack_empty;

    else {
        *popped_element = S->data[S->top];
        S->data[S->top] = 0;
        S->top = S->top - 1;

    }

    if (S->top < S->current_size/4)
    {
        S->data = (stack_element *)realloc(S->data, S->current_size / 2);
    }

}

void Push (stack *S, stack_element new_element)
{
    IsOk(S);

    if (S->top < S->current_size)
    {
        S->data[S -> top ++] = new_element;
        S->top ++;
    }
    else
    {
        S->data = (stack_element *)realloc(S->data, S->current_size * 2);
        S->current_size = S->current_size * 2;
    }


}