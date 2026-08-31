#include "tt_stack.h"
#include <stdio.h>

int main()
{
    Stack stack;

    stack_initialize(&stack, 10);

    printf("Void *: %d\n", sizeof(void *));
    printf("Stack.items: %d\n", sizeof(stack.items));

    stack_finalize(&stack, true);

    return 0;
}

