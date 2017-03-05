#include "common.h"
#include "gen.h"

int 	gen_int(int *value)
{
	//srand((unsigned)time(NULL));
	return rand();
}

void	gen_arr(int arr[], int size)
{
	int i = 0;
	//srand((unsigned)time(NULL));
	while(i < size) 
	{
		arr[i++] = rand();
	}
}


// please make sure: size <= RAND_MAX
void	gen_sorted_arr(int arr[], int size)
{
	int i = 0;
	//srand((unsigned)time(NULL));
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
	//srand((unsigned)time(NULL));
	while(i < size) 
	{
		arr[i++] = min + rand() % (max - min + 1);
	}
}

void	gen_basic_sorted_arr(int arr[], int size, int min, int max)
{
	int i = 0;
	//srand((unsigned)time(NULL));
	while(i < size) 
	{
		arr[i++] = min + rand() % (max - min + 1);
	}
	// sort the arr
	qsort(arr, size, sizeof(int), int_compare);
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
	//srand((unsigned)time(NULL));
	value = min + rand() % (max - min + 1);	
	while(i < size)
		arr[i++] = value;	
}
