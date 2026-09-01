#include "tt_stack.h"
#include <stdio.h>

int main()
{
    Stack stack;

    stack_initialize(&stack, 10);
    
    stack_push_int(&stack, 20);
    stack_push_int(&stack, 30);

    int a, b;

    stack_pop_int(&stack, &a);
    stack_pop_int(&stack, &b);

    printf("a: %d\n", a);
    printf("b: %d\n", b);

    stack_finalize(&stack, true);

    return 0;
}

