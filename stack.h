#ifndef STACK_H
#define STACK_H


typedef struct 
{
	int *base;
	int *top;
	int capacity;
	int	size;
}STACK;

STACK *	stack_create(int size);

int		stack_push(STACK *stack, int value);
int		stack_pop(STACK *stack);
int		stack_top(STACK *stack);

int 	stack_is_empty(STACK *stack);
void	stack_free(STACK *stack);

void	stack_show(STACK *stack);

#endif
