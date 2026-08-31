#include <stdlib.h>
#include "tt_stack.h"

/* Stack initialization and finalization */

bool stack_initialize(Stack *stack, size_t capacity)
{
    if (!stack)
        return false;

    stack->items = NULL;
    stack->count = 0;
    stack->capacity = 0;
    
    if (capacity > 0)
    {
        stack->items = malloc(sizeof(stack->items) * capacity);
        
        if (!stack->items)
            return false;

        for(size_t i = 0; i < capacity; ++i)
            stack->items[i] = NULL;
    }

    stack->capacity = capacity;

    return true;
}

void stack_finalize(Stack *stack, bool free_items)
{
    if (!stack)
        return;

    if (stack->items)
    {
        if (free_items)
        {
            for (size_t i = 0; i < stack->count; i++)
                free(stack->items[i]);
        }

        free(stack->items);
    }

    stack->items = NULL;
    stack->count = 0;
    stack->capacity = 0;
}

/* Core stack operations */

bool stack_push(Stack *stack, void *item)
{
    if (!stack)
        return false;
    
    if (!stack->items || stack->count >= stack->capacity)
        return false;

    stack->items[stack->count++] = item;

    return true;
}

void *stack_pop(Stack *stack)
{
    if (!stack)
        return NULL;
    
    if (!stack->items || stack->count == 0)
        return NULL;
    
    --stack->count;

    void *item = stack->items[stack->count];

    stack->items[stack->count] = NULL;

    return item;
}

void *stack_peek(Stack *stack)
{
    if (!stack)
        return NULL;
    
    if (!stack->items || stack->count == 0)
        return NULL;
    
    return stack->items[stack->count - 1];
}

/* Type specific push */

bool stack_push_int(Stack *stack, int value)
{
    int *ptr = (int *) malloc(sizeof(int));
    
    *ptr = value;

    return stack_push(stack, ptr);
}

bool stack_push_char(Stack *stack, char value)
{
    char *ptr = (char *) malloc(sizeof(char));
    
    *ptr = value;

    return stack_push(stack, ptr);
}

bool stack_push_float(Stack *stack, float value)
{
    float *ptr = (float *) malloc(sizeof(float));
    
    *ptr = value;

    return stack_push(stack, ptr);
}

bool stack_push_double(Stack *stack, double value)
{
    double *ptr = (double *) malloc(sizeof(double));
    
    *ptr = value;

    return stack_push(stack, ptr);
}

bool stack_push_str(Stack *stack, char *value)
{
    return stack_push(stack, value);
}

/* Type specific pop */

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
    return (char *) stack_pop(stack);
}

