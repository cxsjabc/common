#include <stdlib.h>
#include <string.h>

#include "stack.h"
#include "common.h"


STACK *stack_create(int size)
{
	STACK *stack = (STACK *)malloc(sizeof(STACK));
	int *p = NULL;
	
	ASSERT(stack);
	if(!stack)
		goto label_alloc_fail;
	
	p = (int *)malloc(sizeof(int) * size);
	if(!p)
		goto label_alloc_fail;	

	stack->base = p;
	stack->top = p;
	stack->size = 0;
	stack->capacity = size;	

	return stack;

label_alloc_fail:
	if(p)
		free(p);

	if(stack)
		free(stack);

	return stack;
}



int		stack_push(STACK *stack, int value)
{
	//printf("size:%d, capacity:%d\n", stack->size, stack->capacity);
	if(stack->size < stack->capacity) {
		// just add the value
		stack->base[stack->size] = value;
		++(stack->size);
		++(stack->top);
	} else {
		// alloc a big memory
		int *new_mem = (int *)malloc(2 * stack->size * sizeof(int));
		if(!new_mem)
			goto label_alloc_fail;

		memcpy(new_mem, stack->base, sizeof(int) * stack->size);
		free(stack->base);
		stack->base = new_mem;

		stack->base[stack->size] = value;
		++(stack->size);
		++(stack->top);
		stack->capacity <<= 1;
	}

	return 1;
label_alloc_fail:
	printf("Fatal Error: not enough memory!\n");
	return 0;
}

int		stack_pop(STACK *stack)
{
	int value = stack->base[stack->size - 1];
	stack->size--;
	return value;
}

int		stack_top(STACK *stack)
{
	return stack->base[stack->size - 1];
}

int 	stack_is_empty(STACK *stack)
{
	return stack->size == 0;
}

void	stack_free(STACK *stack)
{
	if(stack->base)
		free(stack->base);

	if(stack)
		free(stack);
}


void 	stack_show(STACK *stack)
{
	int i;
	for(i = 0; i < stack->size; ++i) {
		printf("%d ", stack->base[i]);
	}
	printf("\n");
}


