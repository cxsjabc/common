#include "common.h"

int is_arr_sorted(int arr[], int size)
{
	int i = 0;
	while(i < size - 1) {
		if(arr[i] > arr[i + 1]) {
			printf("failed:i:%d,j:%d,arr[i]:%d, arr[j]:%d\n", i, i + 1, arr[i], arr[i + 1]);
			return 0;
		}
		++i;
	}
	return 1;
}

void	show_arr(int arr[], int size)
{
	int i = 0;
	while(i < size) {
		printf("%d ", arr[i]);
		++i;
		if(i != 0 && i % 10 == 0)
			printf("\n");
	}
	printf("\n");
}
	
int is_arr_equal(int arr1[], int size1, int arr2[], int size2)
{
	int i;
	if(size1 != size2)
		return 0;
	for(i = 0; i < size1; ++i)
		if(arr1[i] != arr2[i])
			return 0;
	return 1;
}

int	is_arr_equal_no_index(int arr1[], int size1, int arr2[], int size2)
{
	if(size1 != size2)
		return 0;	
	qsort(arr1, size1, sizeof(int), int_compare);
	qsort(arr2, size2, sizeof(int), int_compare);
	return is_arr_equal(arr1, size1, arr2, size2);
}

// start_value: 4, size: 5 , arr: 4 5 6 7 8 
void	init_basic_arr(int arr[], int size, int start_value)
{
	int i;
	for(i = 0; i < size; ++i)
		arr[i] = start_value + i;
}

// reset_value: 3, size: 5, arr: 3 3 3 3 3 
void	reset_basic_arr(int arr[], int size, int reset_value)
{
	int i;
	for(i = 0; i < size; ++i)
		arr[i] = reset_value;
}

// start_value: 4, size: 5, arr: 8 7 6 5 4 
void	init_reverse_basic_arr(int arr[], int size, int start_value)
{
	int i;
	for(i = size - 1; i >= 0; --i)
		arr[i] = start_value + (size - i - 1);
}


PArray array_create(int capacity)
{
	PArray arr = (PArray)malloc(sizeof(Array));
	int *buf = NULL;

	if(!arr)
		goto label_alloc_fail;

	buf = (int *)malloc(sizeof(int) * capacity);
	if(!buf)
		goto label_alloc_fail;	
	arr->capacity = capacity;
	arr->size = 0;
	arr->buf = buf;
	return arr;

label_alloc_fail:
	if(buf)
		free(buf);
	if(arr)
		free(arr);
	return NULL;

}

int		array_push_back(PArray arr, int value)
{
	if(arr->size < arr->capacity) {
		arr->buf[arr->size] = value;
		++(arr->size);
		LOG_V("Add value:%d", value);
		return 1;
	} else {
		// alloc a bigger buffer
		int *new_buf;
		new_buf = (int *)malloc(2 * arr->capacity * sizeof(int));
		if(!new_buf)
			goto label_alloc_fail;
		memcpy(new_buf, arr->buf, sizeof(int) * arr->capacity);
		free(arr->buf);

		arr->buf = new_buf;
		arr->buf[arr->size] = value;
		arr->capacity = 2 * arr->capacity;
		(arr->size)++;

		LOG_V("Add value:%d,real value:%d, size:%d", value, arr->buf[arr->size -1], arr->size);
		return 1;

	label_alloc_fail:
		return 0;
	}
}

int		array_pop_back(PArray arr)
{
	if(arr->size == 0)
		return 0;

	(arr->size)--;
	return 1;
}

void	array_free(PArray arr)
{
	if(arr->buf)
		free(arr->buf);
	if(arr)
		free(arr);
}

void	array_show(PArray arr)
{
	int i;

	for(i = 0; i < arr->size; ++i)
		printf("%d ", arr->buf[i]);

	printf("\n");
}

