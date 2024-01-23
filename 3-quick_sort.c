#include "sort.h"

/**
 * swap - Swaps two integers in an array.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * lomuto_partition - Partitions the array using the Lomuto scheme.
 * @array: The array to be partitioned.
 * @low: The low index of the partition.
 * @high: The high index of the partition.
 * @size: The size of the array.
 * 
 * Return: The index of the pivot element after partitioning.
 */
size_t lomuto_partition(int *array, ssize_t low, ssize_t high, size_t size)
{
    int pivot = array[high];
    ssize_t i = low - 1, j;

    for (j = low; j <= high - 1; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            swap(&array[i], &array[j]);
            if (i != j)
                print_array(array, size);
        }
    }
    swap(&array[i + 1], &array[high]);
    if (i + 1 != high)
        print_array(array, size);
    return (i + 1);
}

/**
 * quicksort_recursive - Recursive function to implement quicksort.
 * @array: The array to be sorted.
 * @low: The low index of the partition.
 * @high: The high index of the partition.
 * @size: The size of the array.
 */
void quicksort_recursive(int *array, ssize_t low, ssize_t high, size_t size)
{
    if (low < high)
    {
        size_t partition_index = lomuto_partition(array, low, high, size);

        quicksort_recursive(array, low, partition_index - 1, size);
        quicksort_recursive(array, partition_index + 1, high, size);
    }
}

/**
 * quick_sort - Sorts an array of integers using quicksort.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quicksort_recursive(array, 0, size - 1, size);
}
