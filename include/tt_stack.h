#ifndef TT_STACK_H
#define TT_STACK_H

/* Stack definition */

struct _Stack
{
    void **data;
    int top;
    int size;
};

typedef struct _Stack Stack;

/* Stack creation and destruction */

bool stack_initialize(Stack *stack, int size);

void stack_finalize(Stack *stack, bool free_data);

Stack *stack_new(int size);

void stack_free(Stack *stack, bool free_data);

/* Stack operations */

bool stack_push(Stack *stack, void *value);

void *stack_pop(Stack *stack);

/* Type specific operations */

bool stack_push_int(Stack *stack, int value);

bool stack_push_char(Stack *stack, char value);

bool stack_push_float(Stack *stack, float value);

bool stack_push_double(Stack *stack, double value);

bool stack_push_str(Stack *stack, char *value);

int stack_pop_int(Stack *stack);

char stack_pop_char(Stack *stack);

float stack_pop_float(Stack *stack);

double stack_pop_double(Stack *stack);

char *stack_pop_str(Stack *stack);

#endif

