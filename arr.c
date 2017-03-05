#include "common.h"

int is_arr_sorted(int arr[], int size)
{
	int i = 0;
	while(i < size - 1) {
		if(arr[i] > arr[i + 1])
			return 0;
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
	

