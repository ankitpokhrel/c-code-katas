#include <assert.h>

long int nth_fibonacci_number(unsigned int n)
{
    if (n == 0) {
        return 0;
    }

    if (n <= 2) {
        return 1;
    }

    return nth_fibonacci_number(n - 1) + nth_fibonacci_number(n - 2);
}

int main()
{
    int fibonacci_numbers[13] = {
        0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 233, 75025, 102334155
    };

    unsigned int fibonacci_number_positions[13] = {
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 13, 25, 40
    };

    for (int i = 0; i < 13; i++) {
        assert(fibonacci_numbers[i] == nth_fibonacci_number(fibonacci_number_positions[i]));
    }

    return 0;
}
