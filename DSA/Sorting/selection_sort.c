#include <stdio.h>
#include <stdlib.h>

void swap(int *, int *);

/**
 * Selection sort algorithm.
 *
 * @param int input Array to sort
 * @param int n Number of data in search array
 *
 * @return void
 */
void selection_sort(int *input, int n)
{
    int min;

    for (int i = 0; i < n - 1; i++) {
        min = i;

        for (int j = i + 1; j < n; j++) {
            if (input[j] < input[min]) {
                min = j;
            }
        }

        if (min != i) {
            swap(input + i, input + min);
        }
    }
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

    selection_sort(input, n);

    for (int i = 0; i < n; i++) {
        printf("%d\t", *(input + i));
    }

    free(input);
}
