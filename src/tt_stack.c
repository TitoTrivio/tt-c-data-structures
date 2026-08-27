#include "tt_stack.h"
#include <stdlib.h>

bool stack_initialize(Stack *stack, int size)
{
    if(size < 0)
        return false;
    
    stack->data = NULL;
    
    if(size != 0)
    {
        stack->data = malloc(size * sizeof(void*));
        
        if(!stack->data)
            return false;
    }

    stack->top = -1;
    stack->size = size;

    return true;
}

void stack_finalize(Stack *stack, bool free_data)
{
    if(!stack)
        return;

    if(stack->data)
    {
        if(free_data)
        {
            for(int i = 0; i <= stack->top; i++)
                free(stack->data[i]);
        }

        free(stack->data);
    }

    stack->data = NULL;
    stack->top = -1;
    stack->size = 0;
}

Stack *stack_new(int size)
{
    Stack *stack = (Stack*) malloc(sizeof(Stack));

    if(!stack_initialize(stack, size))
    {
        free(stack);
        return NULL;
    }

    return stack;
}

void stack_free(Stack *stack, bool free_data)
{
    if(!stack)
        return;

    stack_finalize(stack, free_data);

    free(stack);
}

bool stack_push(Stack *stack, void *value)
{
    if(stack->top + 1 >= stack->size)
        return false;

    stack->data[++stack->top] = value;

    return true;
}

void *stack_pop(Stack *stack)
{
    if(stack->top < 0)
        return NULL;

    void *value = stack->data[stack->top];

    stack->data[stack->top] = NULL;

    stack->top--;

    return value;
}

bool stack_push_int(Stack *stack, int value)
{
    int *ptr = (int*) malloc(sizeof(int));
    
    *ptr = value;

    return stack_push(stack, ptr);
}

bool stack_push_char(Stack *stack, char value)
{
    char *ptr = (char*) malloc(sizeof(char));
    
    *ptr = value;

    return stack_push(stack, ptr);
}

bool stack_push_float(Stack *stack, float value)
{
    float *ptr = (float*) malloc(sizeof(float));
    
    *ptr = value;

    return stack_push(stack, ptr);
}

bool stack_push_double(Stack *stack, double value)
{
    double *ptr = (double*) malloc(sizeof(double));
    
    *ptr = value;

    return stack_push(stack, ptr);
}

bool stack_push_str(Stack *stack, char *value)
{
    return stack_push(stack, value);
}

int stack_pop_int(Stack *stack)
{
    int *ptr = stack_pop(stack);

    int value = *ptr;

    free(ptr);

    return value;
}

char stack_pop_char(Stack *stack)
{
    char *ptr = stack_pop(stack);

    char value = *ptr;

    free(ptr);

    return value;
}

float stack_pop_float(Stack *stack)
{
    float *ptr = stack_pop(stack);

    float value = *ptr;

    free(ptr);

    return value;
}

double stack_pop_double(Stack *stack)
{
    double *ptr = stack_pop(stack);

    double value = *ptr;

    free(ptr);

    return value;
}

char *stack_pop_str(Stack *stack)
{
    return (char*) stack_pop(stack);
}

