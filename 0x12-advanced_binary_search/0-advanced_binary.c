#include <stdio.h>

int advanced_binary(int *array, size_t size, int value)
{
    if (array == NULL || size == 0)
        return (-1);

    int low = 0, high = size - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        printf("Searching in array: ");
        for (size_t i = low; i <= high; i++)
        {
            printf("%d", array[i]);
            if (i != high)
                printf(", ");
        }
        printf("\n");

        if (array[mid] == value)
        {
            if (mid == 0 || array[mid - 1] != value)
                return (mid);
            else
                high = mid - 1;
        }
        else if (array[mid] > value)
            high = mid - 1;
        else
            low = mid + 1;
    }

    return (-1);
}
