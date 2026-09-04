#include <stdio.h>
#include "tt_stack.h"

int main()
{
    Stack stack;

    stack_initialize(&stack, 4);

    stack_push(&stack, "Four", 5);
    stack_push(&stack, "Three", 6);
    stack_push(&stack, "Two", 4);
    stack_push(&stack, "One", 4);

    char text[6];

    stack_pop(&stack, text, 4);
    printf("%s\n", text);
    stack_pop(&stack, text, 4);
    printf("%s\n", text);
    stack_pop(&stack, text, 6);
    printf("%s\n", text);

    stack_finalize(&stack);
}

