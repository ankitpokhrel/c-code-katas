#include <stdio.h>
#include <stdlib.h>

/**
 * Linear search algorithm.
 *
 * @param int a Search array
 * @param int find Data to search
 * @param int n Number of data in search array
 *
 * @return int Index of found data or -1
 */
int linear_search(int *a, int find, int n)
{
    for (int i = 0; i < n; i++) {
        if (find == *(a+i)) {
            return i;
        }
    }

    return -1;
}

int main()
{
    int n, find;

    printf("How many items? ");
    scanf("%d", &n);

    int *input = (int *) malloc(n * sizeof(int));

    printf("Enter numbers: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", input + i);
    }

    printf("Find: ");
    scanf("%d", &find);

    int position = linear_search(input, find, n);

    if (position != -1) {
        printf("Data found at position %d", position);
    } else {
        printf("Data not found");
    }

    free(input);

    return 0;
}
