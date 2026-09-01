#ifndef TT_STACK_H
#define TT_STACK_H

#include <stddef.h>

/* Stack definition */

struct _Stack
{
    void **items;
    size_t count;
    size_t capacity;
};

typedef struct _Stack Stack;

/* Stack initialization and finalization */

bool stack_initialize(Stack *stack, size_t capacity);

void stack_finalize(Stack *stack, bool free_items);

/* Core stack operations */

bool stack_push(Stack *stack, void *item);

bool stack_pop(Stack *stack, void **item);

bool stack_peek(Stack *stack, void **item);

/* Type specific push */

bool stack_push_int(Stack *stack, int value);

bool stack_push_char(Stack *stack, char value);

bool stack_push_float(Stack *stack, float value);

bool stack_push_double(Stack *stack, double value);

bool stack_push_str(Stack *stack, char *value);

/* Type specific pop */

bool stack_pop_int(Stack *stack, int *item);

bool stack_pop_char(Stack *stack, char *item);

bool stack_pop_float(Stack *stack, float *item);

bool stack_pop_double(Stack *stack, double *item);

//bool stack_pop_str(Stack *stack, char *item);

#endif

