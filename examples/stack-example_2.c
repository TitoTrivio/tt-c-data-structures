#include "tt_stack.h"
#include <stdio.h>

int main(void)
{
    Stack str_stack, int_stack;

    stack_initialize(&str_stack, 3);
    stack_initialize(&int_stack, 3);

    stack_push_str(&str_stack, "Three\n");
    stack_push_str(&str_stack, "Two\n");
    stack_push_str(&str_stack, "One\n");
    
    stack_push_int(&int_stack, 3);
    stack_push_int(&int_stack, 2);
    stack_push_int(&int_stack, 1);

    printf(stack_pop_str(&str_stack));
    printf(stack_pop_str(&str_stack));
    printf(stack_pop_str(&str_stack));
    
    printf("%d\n", stack_pop_int(&int_stack));
    printf("%d\n", stack_pop_int(&int_stack));
    printf("%d\n", stack_pop_int(&int_stack));

    stack_finalize(&str_stack, false);
    stack_finalize(&int_stack, true);
    
    return 0;
}
