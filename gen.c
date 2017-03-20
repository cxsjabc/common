#include "common.h"
#include "gen.h"

#define FORCE_SRAND		0

int 	gen_int(int *value)
{
#if FORCE_SRAND	
	srand((unsigned)time(NULL));
#endif
	return rand();
}

void	gen_arr(int arr[], int size)
{
	int i = 0;
#if FORCE_SRAND	
	srand((unsigned)time(NULL));
#endif
	while(i < size) 
	{
		arr[i++] = rand();
	}
}


// please make sure: size <= RAND_MAX
void	gen_sorted_arr(int arr[], int size)
{
	int i = 0;
#if FORCE_SRAND	
	srand((unsigned)time(NULL));
#endif
	while(i < size) 
	{
			arr[i++] = rand();
	}
	// sort the arr
	qsort(arr, size, sizeof(int), int_compare);
}

void	gen_basic_arr(int arr[], int size, int min, int max)
{
	int i = 0;
#if FORCE_SRAND	
	srand((unsigned)time(NULL));
#endif
	while(i < size) 
	{
		arr[i++] = min + rand() % (max - min + 1);
	}
}

void	gen_basic_sorted_arr(int arr[], int size, int min, int max)
{
	int i = 0;
#if FORCE_SRAND	
	srand((unsigned)time(NULL));
#endif
	while(i < size) 
	{
		arr[i++] = min + rand() % (max - min + 1);
	}
	// sort the arr
	qsort(arr, size, sizeof(int), int_compare);
}

void	gen_basic_desc_arr(int arr[], int size, int min, int max)
{
	int i = 0;
#if FORCE_SRAND	
	srand((unsigned)time(NULL));
#endif
	while(i < size) 
	{
		arr[i++] = min + rand() % (max - min + 1);
	}
	// sort the arr
	qsort(arr, size, sizeof(int), int_compare_desc);
		
}

void	gen_fixed_arr(int arr[], int size, int value)
{
	int i = 0;
	while(i < size)
		arr[i++] = value;	
}

void	gen_fixed_range_arr(int arr[], int size, int min, int max)
{
	int i = 0;
	int value;
#if FORCE_SRAND	
	srand((unsigned)time(NULL));
#endif
	value = min + rand() % (max - min + 1);	
	while(i < size)
		arr[i++] = value;	
}

#if 0
/* not completed! */
PTree	gen_bst_tree(int size, int max, int min, int init_value)
{
	PTree tree;
	if(init_value == INT_MAX)
		init_value = (max + min) / 2;	
	tree = bst_create(init_value);
	if(!tree)
		return NULL;

	return tree;

label_alloc_fail:
	if(tree)
		bst_free(tree);
	return NULL;
}
#endif
