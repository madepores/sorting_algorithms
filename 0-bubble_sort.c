#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer.
 * @b: The second integer.
 */

void swap_ints(int *a, int *b)
{
    int tempal;

    tempal = *a;
    *a = *b;
    *b = tempal;
}

/**
 * bubble_sort - Sort an array of integers in right order.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 */

void bubble_sort(int *array, size_t size)
{
    size_t i, len = size;
    bool bubbly = false;

    if (array == NULL || size < 2)
        return;

    while (bubbly == false)
    {
        bubbly = true;
        for (i = 0; i < len - 1; i++)
        {
            if (array[i] > array[i + 1])
            {
                swap_ints(array + i, array + i + 1);
                print_array(array, size);
                bubbly = false;
            }
        }
        len--;
    }
}
