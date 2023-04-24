#include "sort.h"

/**
 * sift_down - sifts down the heap
 * @array: array to sort
 * @start: start of the heap
 * @end: end of the heap
 * @size: size of the array
 */
void sift_down(int *array, size_t start, size_t end, size_t size)
{
    size_t root = start;
    size_t child, swap;

    while (2 * root + 1 <= end)
    {
        child = 2 * root + 1;
        swap = root;

        if (array[swap] < array[child])
            swap = child;

        if (child + 1 <= end && array[swap] < array[child + 1])
            swap = child + 1;

        if (swap == root)
            return;
        else
        {
            int tmp = array[root];
            array[root] = array[swap];
            array[swap] = tmp;
            print_array(array, size);
            root = swap;
        }
    }
}

/**
 * heap_sort - sorts an array of integers in ascending order using the Heap
 * sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void heap_sort(int *array, size_t size)
{
    int tmp;
    size_t end;

    if (array == NULL || size < 2)
        return;

    for (end = (size - 2) / 2; (int)end >= 0; end--)
        sift_down(array, end, size - 1, size);

    for (end = size - 1; end > 0; end--)
    {
        tmp = array[end];
        array[end] = array[0];
        array[0] = tmp;
        print_array(array, size);
        sift_down(array, 0, end - 1, size);
    }
}
