#include <assert.h>

int linear_search(int *a, int find, int index, int n)
{
    if (index > n) {
        return -1;
    }

    if (a[index] == find) {
        return index;
    }

    return linear_search(a, find, index + 1, n);
}

int main()
{
    int test_array[10] = {9, 2, 3, 5, 8, 7, 13, 17, 23, 48};

    for (int i = 0; i < 10; i++) {
        assert(i == linear_search(test_array, test_array[i], 0, 10));
    }

    assert(-1 == linear_search(test_array, 81, 0, 10));

    return 0;
}
