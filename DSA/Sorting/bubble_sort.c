#include <stdio.h>
#include <stdlib.h>

void swap(int *, int *);

/**
 * Bubble sort algorithm.
 *
 * @param int input Array to sort
 * @param int n Number of data in search array
 *
 * @return void
 */
void bubble_sort(int *input, int n)
{
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (input[j] > input[j + 1]) {
                swap(input + j, input + j + 1);
            }
        }
    }
}

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

    bubble_sort(input, n);

    for (int i = 0; i < n; i++) {
        printf("%d\t", *(input + i));
    }

    free(input);
}
