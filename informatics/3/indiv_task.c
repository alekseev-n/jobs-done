#include <stdio.h>
#include <stdlib.h>
#include "/home/students/a/alekseev.nv/lib/getters.h"
#include "../../lib/arr.h"

int sum_num(int n);

int by_sum(int **arr, int *len_arr, int **new_arr, int *new_len, int M) {
	int count = 0;
	
	int s = 0;

	while (count < *len_arr) {
		s = sum_num((*arr)[count]);
		if (s == M) {
		    (*new_arr)[*new_len] = (*arr)[count];
		    *new_len += 1;
		    del_elem(arr, len_arr, count);
		    
		    count -= 1;
		}
		count += 1;
	}
	return 1;
}


int sum_num(int n) {
	int res = 0;
	while (n > 0) {
		res += n % 10;
		n /= 10;
	}
	return res;
}
