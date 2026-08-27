#include "tt_stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    Stack stack;
    stack_initialize(&stack, 10);

    int *number = (int*) malloc(sizeof(int));
    char *text = (char*) malloc(12 * sizeof(char));

    *number = 3;
    strcpy(text, "Hello World");

    stack_push(&stack, number);
    stack_push(&stack, text);

    char *text2 = (char*) stack_pop(&stack);
    int *number2 = (int*) stack_pop(&stack);

    printf("%s\n", text2);
    printf("%d\n", *number2);

    stack_finalize(&stack, true);
    free(text2);
    free(number2);
    
    return 0;
}

