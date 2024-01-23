#include "sort.h"

/**
 * selection_sort - Sorts an array of integers using selection sort.
 * @array: The array to be sorted.
 * @size: The size of the array.
 *
 * Description: Prints the array after each time two elements are swapped.
 */
void selection_sort(int *array, size_t size)
{
    size_t i, j, min_idx;

    if (array == NULL || size < 2)
        return;

    for (i = 0; i < size - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < size; j++)
        {
            if (array[j] < array[min_idx])
                min_idx = j;
        }

        if (min_idx != i)
        {
            /* Swap array[i] and array[min_idx] */
            int temp = array[i];
            array[i] = array[min_idx];
            array[min_idx] = temp;

            print_array(array, size);
        }
    }
}
