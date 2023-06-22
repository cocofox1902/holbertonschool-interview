#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

void merge(int *holder, int *array, int mid, size_t size);
void merge_sort(int *array, size_t size);
void merge_sort_holder(int *array, size_t size, int *holder);

#endif
