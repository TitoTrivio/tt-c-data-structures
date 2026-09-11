#include <stdio.h>
#include <stdlib.h>
#include "tt_stack.h"

#define TEXT_LENGTH 100

int main()
{
    Stack stack;

    stack_initialize(&stack, 10);

    char text[TEXT_LENGTH];

    char op_str[TEXT_LENGTH];
    char *endptr;

    long op = 0;

    while (op != 9)
    {
        printf("Stack operations:\n1 - Push\n2 - Pop\n3 - Peek\n4 - Is Empty\n9 - Quit\n");
        
        fgets(op_str, TEXT_LENGTH, stdin);

        op = strtol(op_str, &endptr, 10);
    
        printf("\n");

        switch(op)
        {
            case 1:
                printf("Type some text to be pushed to the stack:\n");
                fgets(text, TEXT_LENGTH, stdin);
                if (stack_push(&stack, text, TEXT_LENGTH))
                    printf("Pushed successfully!\n");
                else
                    printf("Push failed!\n");
                break;
            
            case 2:
                if (stack_pop(&stack, text, TEXT_LENGTH))
                    printf("Popped text: %s\n", text);
                else
                    printf("Pop failed!\n");
                break;

            case 3:
                if (stack_peek(&stack, text, TEXT_LENGTH))
                    printf("Peeked text: %s\n", text);
                else
                    printf("Peek failed!\n");
                break;

            case 4:
                printf("Is Empty: ");
                if (stack_is_empty(&stack))
                    printf("True\n");
                else
                    printf("False\n");
                break;
        }

        printf("\n");
    }

    stack_finalize(&stack);
}

