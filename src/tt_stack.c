#include <stdlib.h>
#include <string.h>
#include "tt_stack.h"

// Stack initialization and finalization

bool stack_initialize(Stack *stack, size_t capacity)
{
    if (!stack)
        return false;

    stack->items = NULL;
    stack->count = 0;
    stack->capacity = 0;
    
    if (capacity > 0)
    {
        stack->items = malloc(sizeof(void *) * capacity);
        
        if (!stack->items)
            return false;

        for(size_t i = 0; i < capacity; ++i)
            stack->items[i] = NULL;
    }

    stack->capacity = capacity;

    return true;
}

void stack_finalize(Stack *stack)
{
    if (!stack)
        return;

    if (stack->items)
    {
        for (size_t i = 0; i < stack->count; ++i)
            free(stack->items[i]);

        free(stack->items);
    }

    stack->items = NULL;
    stack->count = 0;
    stack->capacity = 0;
}

// Stack operations

bool stack_push(Stack *stack, void *item, size_t size)
{
    if (!stack)
        return false;
    
    if (!stack->items || stack->count >= stack->capacity)
        return false;

    void *ptr = malloc(sizeof(void *));

    memcpy(ptr, item, size);

    stack->items[stack->count++] = ptr;

    return true;
}

bool stack_pop(Stack *stack, void *dest, size_t size)
{
    if (!stack || !dest)
        return false;
    
    if (!stack->items || stack->count == 0)
        return false;
    
    --stack->count;

    memcpy(dest, stack->items[stack->count], size);
    
    stack->items[stack->count] = NULL;

    return true;
}

bool stack_peek(Stack *stack, void *dest, size_t size)
{
    if (!stack || !dest)
        return false;
    
    if (!stack->items || stack->count == 0)
        return false;
    
    memcpy(dest, stack->items[stack->count - 1], size);

    return true;
}

