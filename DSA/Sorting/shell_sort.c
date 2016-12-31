#include <stdio.h>
#include <stdlib.h>

/**
 * Insertion sort algorithm.
 *
 * @param int input Array to sort
 * @param int n Number of data in search array
 *
 * @return void
 */
void insertion_sort(int *input, int n, int span)
{
    int gap, key;

    for (int i = span; i < n; i += span) {
        key = input[i];
        gap = i - span;

        while (gap >= 0 && input[gap] > key) {
            input[gap + span] = input[gap];
            gap -= span;
        }

        input[gap + span] = key;
    }
}

/**
 * Shell sort algorithm.
 *
 * @param int input Array to sort
 * @param int n Number of data in search array
 *
 * @return void
 */
void shell_sort(int *input, int n)
{
    int span = n / 2;

    while (span > 0) {
        //perform insertion sort on subset
        insertion_sort(input, n, span);

        span = span / 2;
    }
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

    shell_sort(input, n);

    for (int i = 0; i < n; i++) {
        printf("%d\t", *(input + i));
    }

    free(input);
}
