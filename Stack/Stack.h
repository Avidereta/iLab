#include <stddef.h>

typedef int stack_element;
struct stack
{
    size_t current_size;
    stack_element* data;
    int top; //

};

bool IsOk (stack* S);
int Dump(stack* S);
int StackInit (stack* S, size_t start_size);
void StackDestroy(stack* S);
bool IsEmpty (stack* S);
int Pop(stack *S, stack_element* popped_element);
int Remove(stack *S);
int Push (stack *S, stack_element new_element);
int Multiply(stack* S);
int Add(stack* S);
int Division(stack* S);
int Subtraction(stack* S);
