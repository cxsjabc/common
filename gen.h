#ifndef GEN_H
#define GEN_H


/*
	Notice: we don't call srand before rand, because caller will often get the same values when calling gen functions with tiny time intervals.
			So, let caller call srand when they need!
*/

int 	gen_int(int *value);
void	gen_arr(int arr[], int size);
void	gen_sorted_arr(int arr[], int size);

void	gen_basic_arr(int arr[], int size, int min, int max);
void	gen_basic_sorted_arr(int arr[], int size, int min, int max);
void	gen_basic_desc_arr(int arr[], int size, int min, int max);

void	gen_fixed_arr(int arr[], int size, int value);
void	gen_fixed_range_arr(int arr[], int size, int min, int max);

#endif
