#include <stdio.h>
#include <stdlib.h> // To call qsort function from the standard library

// Parameter Comparison Function
int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b); // Compare two integers in ascending order
}

int main()
{
    int numbers[] = {5, 2, 9, 1, 7};
    int size = sizeof(numbers) / sizeof(numbers[0]); // Calculate the number of elements in the array

    qsort(numbers, size, sizeof(int), compare); // address of the first element, number of elements, size of each element, comparison function

    for (int i = 0; i < size; i++)
    {
        printf("%d ", numbers[i]);
    }
    return 0;
}