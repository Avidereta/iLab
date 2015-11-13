#include "ErrorList.h"
#include "Stack.h"


int Add(stack* S)
{
    if(!IsOk(S))
        return Dump(S), DUMP_CALLED;

    stack_element a = 0;
    stack_element b = 0;

    int result = Pop(S, &a);
    if (result)
        return result;

    result = Pop(S, &b);
    if (result)
        return result;

    stack_element sum = a + b;
    Push(S, sum);

    if(!IsOk(S))
        return Dump(S), DUMP_CALLED;

    return 0;
}

int Subtraction(stack* S)
{
    if(!IsOk(S))
        return Dump(S), DUMP_CALLED;

    stack_element a = 0;
    stack_element b = 0;

    int result = Pop(S, &a);
    if (result)
        return result;

    result = Pop(S, &b);
    if (result)
        return result;

    stack_element sub = a + b;
    Push(S, sub);

    if(!IsOk(S))
        return Dump(S), DUMP_CALLED;

    if(!IsOk(S))
        return Dump(S), DUMP_CALLED;

    return 0;
}


int Division(stack* S)
{
    if(!IsOk(S))
        return Dump(S), DUMP_CALLED;

    stack_element a = 0;
    stack_element b = 0;

    int result = Pop(S, &a);
    if (result)
        return result;

    result = Pop(S, &b);
    if (result)
        return result;

    stack_element div = a/b;
    Push(S, div);

    if(!IsOk(S))
        return Dump(S), DUMP_CALLED;

    return 0;
}

int Multiply(stack* S)
{
    if(!IsOk(S))
        return Dump(S), DUMP_CALLED;

    stack_element a = 0;
    stack_element b = 0;

    int result = Pop(S, &a);
    if (result)
        return result;

    result = Pop(S, &b);
    if (result)
        return result;

    stack_element mult = a * b;
    Push(S, mult);

    if(!IsOk(S))
        return Dump(S), DUMP_CALLED;

    return 0;
}