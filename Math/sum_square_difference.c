#include <assert.h>

/**
 * General approach to find sum of squares
 * for sequence N.
 *
 * @param int limit
 * @return
 */
unsigned long long sum_of_squares(int limit)
{
    unsigned long long sum = 0;

    for (int i = 1; i <= limit; i++) {
        sum += (i * i);
    }

    return sum;
}

/**
 * General approach to find square of sum
 * for sequence N.
 *
 * @param int limit
 * @return
 */
unsigned long long square_of_sum(int limit)
{
    unsigned long long sum = 0;

    for (int i = 1; i <= limit; i++) {
        sum += i;
    }

    return sum * sum;
}

/**
 * Sum of squares of N sequence is given by
 * (N * (N+1) * (2N+1)) / 6
 *
 * @param int limit
 *
 * @return unsigned long long
 */
unsigned long long sum_of_squares_efficient(int limit)
{
    return (unsigned long long) (limit * (limit + 1) * (2 * limit + 1)) / 6;
}

/**
 * Sum of digits of N sequence is given by
 * (N * (N+1)) / 2
 *
 * @param int limit
 *
 * @return unsigned long long
 */
unsigned long long square_of_sum_efficient(int limit)
{
    int sum = (limit * (limit + 1)) / 2;

    return (unsigned long long) sum * sum;
}

int main()
{
    assert(2640 == (square_of_sum(10) - sum_of_squares(10)));
    assert(41230 == (square_of_sum(20) - sum_of_squares(20)));
    assert(1582700 == (square_of_sum(50) - sum_of_squares(50)));
    assert(25164150 == (square_of_sum(100) - sum_of_squares(100)));

    assert(2640 == (square_of_sum_efficient(10) - sum_of_squares_efficient(10)));
    assert(41230 == (square_of_sum_efficient(20) - sum_of_squares_efficient(20)));
    assert(1582700 == (square_of_sum_efficient(50) - sum_of_squares_efficient(50)));
    assert(25164150 == (square_of_sum_efficient(100) - sum_of_squares_efficient(100)));

    return 0;
}
