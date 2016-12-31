#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(int *, int, int);

/**
 * Merge sort algorithm.
 *
 * @param int input Array to sort
 * @param int n Number of data in search array
 *
 * @return void
 */
void merge_sort(int *data, int start, int end)
{
    if (start == end) {
        return;
    }

    int mid = (start + end) / 2;

    if (start < end) {
        merge_sort(data, start, mid);
        merge_sort(data, mid + 1, end);

        merge(data, start, end);
    }
}

/**
 * Merge two sub arrays.
 *
 * @param int data Array
 * @param int start Start index of an array
 * @param int end End index of an array
 *
 * @return void
 */
void merge(int *data, int start, int end)
{
    int mid = (start + end) / 2;

    int i = start, j = mid + 1, k = 0;

    int *temp = (int *) malloc((end - start) * sizeof(int));

    while (i <= mid && j <= end) {
        if (*(data + i) < *(data + j)) {
            temp[k++] = data[i++];
        } else {
            temp[k++] = data[j++];
        }
    }

    //leftovers from left sub array
    while (i <= mid) {
        temp[k++] = data[i++];
    }

    //leftovers from right sub array
    while (j <= end) {
        temp[k++] = data[j++];
    }

    //copy items to original array
    memcpy(data + start, temp, (end - start + 1) * sizeof(int));

    free(temp);
}

int main()
{
    int n;

    printf("How many numbers? ");
    scanf("%d", &n);

    int *input = (int *) malloc(n * sizeof(int));

    printf("Enter %d numbers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &input[i]);
    }

    merge_sort(input, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%d\t", *(input + i));
    }

    free(input);
}
