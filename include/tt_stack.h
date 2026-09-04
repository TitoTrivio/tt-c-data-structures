#ifndef TT_STACK_H
#define TT_STACK_H

#include <stddef.h>

// Stack definition

struct _Stack
{
    void **items;
    size_t count;
    size_t capacity;
};

typedef struct _Stack Stack;

// Stack initialization and finalization

bool stack_initialize(Stack *stack, size_t capacity);

void stack_finalize(Stack *stack);

// Stack operations

bool stack_push(Stack *stack, void *item, size_t size);

bool stack_pop(Stack *stack, void *dest, size_t size);

bool stack_peek(Stack *stack, void *dest, size_t size);

#endif

