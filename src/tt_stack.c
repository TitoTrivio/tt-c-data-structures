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
        stack->items = malloc(sizeof(*stack->items) * capacity);
        
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
            for (size_t i = 0; i < stack->count; ++i)
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

bool stack_pop(Stack *stack, void **item)
{
    if (!stack || !item)
        return false;
    
    if (!stack->items || stack->count == 0)
        return false;
    
    --stack->count;

    *item = stack->items[stack->count];
    
    stack->items[stack->count] = NULL;

    return true;
}

bool stack_peek(Stack *stack, void **item)
{
    if (!stack || !item)
        return false;
    
    if (!stack->items || stack->count == 0)
        return false;
    
    *item = stack->items[stack->count - 1];

    return true;
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

bool stack_pop_int(Stack *stack, int *item)
{
    void *ptr;

    bool popped = stack_pop(stack, &ptr);

    if (!popped)
        return false;

    *item = *(int *)ptr;

    free(ptr);

    return true;
}

bool stack_pop_char(Stack *stack, char *item)
{
    void *ptr;

    bool popped = stack_pop(stack, &ptr);

    if (!popped)
        return false;

    *item = *(char *)ptr;

    free(ptr);

    return true;
}

bool stack_pop_float(Stack *stack, float *item)
{
    void *ptr;

    bool popped = stack_pop(stack, &ptr);

    if (!popped)
        return false;

    *item = *(float *)ptr;

    free(ptr);

    return true;
}

bool stack_pop_double(Stack *stack, double *item)
{
    void *ptr;

    bool popped = stack_pop(stack, &ptr);

    if (!popped)
        return false;

    *item = *(double *)ptr;

    free(ptr);

    return true;
}
/*
bool stack_pop_str(Stack *stack, char *item)
{
    return stack_pop(stack, &item);
}
*/
