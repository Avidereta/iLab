#include <stddef.h>

typedef int stack_element;
struct stack;
bool IsOk (stack* S);
int Dump(stack* S);
int StackInit (stack* S, size_t start_size);
void StackDestroy(stack* S);
bool IsEmpty (stack* S);
int Pop(stack *S, stack_element* popped_element);
int Push (stack *S, stack_element new_element);