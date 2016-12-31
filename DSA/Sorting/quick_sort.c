#include <stdio.h>
#include <stdlib.h>

void swap(int *, int *);

/**
 * Partitioning logic.
 *
 * @param integer input Input array
 * @param int start Start index of an array
 * @param int end End index of an array
 *
 * @return int Partitioning pivot
 */
int partition(int *input, int start, int end)
{
    int pivot = start;

    for (int i = start; i < end; i++) {
        if (input[i] <= input[end]) {
            swap(input + i, input + pivot);
            pivot++;
        }
    }

    swap(input + pivot, input + end);

    return pivot;
}

/**
 * Quick sort algorithm.
 *
 * @param int input Array to sort
 * @param int start Start index of an array
 * @param int end End index of an array
 *
 * @return void
 */
void quick_sort(int *input, int start, int end)
{
    if (start >= end) {
        return;
    }

    int pivot = partition(input, start, end);

    quick_sort(input, start, pivot - 1);
    quick_sort(input, pivot + 1, end);
}

/**
 * Swap two integers.
 *
 * @param int a
 * @param int b
 *
 * @return void
 */
void swap(int *a, int *b)
{
    int temp = *b;

    *b = *a;
    *a = temp;
}

int main()
{
    int n;

    printf("How many numbers? ");
    scanf("%d", &n);

    int *input = (int *) malloc(n * sizeof(int));

    printf("Enter %d numbers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", input + i);
    }

    quick_sort(input, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%d\t", *(input + i));
    }

    free(input);
}
