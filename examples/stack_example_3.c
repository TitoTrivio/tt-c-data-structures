#include "tt_stack.h"
#include <stdio.h>

int main(void)
{
    Stack str_stack;

    stack_initialize(&str_stack, 3);

    stack_push_str(&str_stack, "Three");
    stack_push_str(&str_stack, "Two");
    stack_push_str(&str_stack, "One");

    char *a, *b, *c;

    stack_pop_str(&str_stack, &a);
    stack_pop_str(&str_stack, &b);
    stack_pop_str(&str_stack, &c);

    stack_finalize(&str_stack, false);

    printf("%s %s %s\n", a, b, c);

    return 0;
}

