#ifndef SORT_H
#define SORT_H


#include <stddef.h>

void print_array(const int *array, size_t size);
void radix_sort(int *array, size_t size);
void counting_sort(int *array, size_t size, int exp);
int get_max(int *array, size_t size);

#endif
