#include "tt_stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    Stack stack;
    int *number_to_push;
    char *text_to_push;
    void *popped_number;
    void *popped_text;

    stack_initialize(&stack, 10);

    number_to_push = (int *) malloc(sizeof(int));
    text_to_push = (char *) malloc(sizeof(char) * 15);

    *number_to_push = 1;
    strcpy(text_to_push, "You are number");

    stack_push(&stack, number_to_push);
    stack_push(&stack, text_to_push);

    stack_pop(&stack, &popped_text);
    stack_pop(&stack, &popped_number);

    printf("%s ", (char *)popped_text);
    printf("%d!\n", *(int *)popped_number);

    stack_finalize(&stack, true);
    
    free(popped_text);
    free(popped_number);
    
    return 0;
}

