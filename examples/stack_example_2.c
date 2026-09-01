#include "tt_stack.h"
#include <stdio.h>

int main(void)
{
    Stack char_stack, int_stack;

    stack_initialize(&char_stack, 3);
    stack_initialize(&int_stack, 3);

    stack_push_char(&char_stack, 'C');
    stack_push_char(&char_stack, 'B');
    stack_push_char(&char_stack, 'A');
    
    stack_push_int(&int_stack, 3);
    stack_push_int(&int_stack, 2);
    stack_push_int(&int_stack, 1);

    char letter;
    int number;

    stack_pop_char(&char_stack, &letter);
    printf("%c\n", letter);
    stack_pop_char(&char_stack, &letter);
    printf("%c\n", letter);
    stack_pop_char(&char_stack, &letter);
    printf("%c\n", letter);

    stack_pop_int(&int_stack, &number);
    printf("%d\n", number);
    stack_pop_int(&int_stack, &number);
    printf("%d\n", number);
    stack_pop_int(&int_stack, &number);
    printf("%d\n", number);

    stack_finalize(&char_stack, true);
    stack_finalize(&int_stack, true);
    
    return 0;
}
