#include <assert.h>

int binary_search(int *a, int find, int start, int end)
{
    if (start > end) {
        return -1;
    }

    int mid = (start + end) / 2;

    if (a[mid] == find) {
        return mid;
    }

    if (find < a[mid]) {
        end = mid - 1;
    } else {
        start = mid + 1;
    }

    return binary_search(a, find, start, end);
}

int main()
{
    int test_array[10] = {2, 3, 5, 7, 8, 9, 13, 17, 23, 48};

    for (int i = 0; i < 10; i++) {
        assert(i == binary_search(test_array, test_array[i], 0, 9));
    }

    assert(-1 == binary_search(test_array, 81, 0, 10));

    return 0;
}
