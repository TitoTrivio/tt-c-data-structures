#ifndef TT_STACK_H
#define TT_STACK_H

#include <stddef.h>

// Stack definition

struct _StackItem
{
    void *data;
    size_t size;
};

typedef struct _StackItem StackItem;

struct _Stack
{
    StackItem *items;
    size_t count;
    size_t capacity;
};

typedef struct _Stack Stack;

// Stack initialization and finalization

bool stack_initialize(Stack *stack, const size_t capacity);

void stack_finalize(Stack *stack);

// Stack operations

bool stack_push(Stack *stack, const void *item, const size_t size);

bool stack_pop(Stack *stack, void *dest, const size_t size);

bool stack_peek(const Stack *stack, void *dest, const size_t size);

#endif

