/**
 * Longest Collatz sequence.
 * https://projecteuler.net/problem=14
 */

#include <assert.h>

unsigned long next_collatz_sequence(unsigned long n)
{
    if (n % 2 == 0) {
        return n / 2;
    }

    return 3 * n + 1;
}

int collatz_sequence(unsigned long n)
{
    int num_sequence = 1;

    while (n > 1) {
        ++num_sequence;

        n = next_collatz_sequence(n);
    }

    return num_sequence;
}

unsigned long longest_collatz_sequence(unsigned long limit)
{
    int sequence, largest = 0;
    unsigned long num = limit;

    for (unsigned long i = limit / 2; i <= limit; i++) {
        sequence = collatz_sequence(i);

        if (sequence > largest) {
            num = i;
            largest = sequence;
        }
    }

    return num;
}

int main()
{
    assert(9 == longest_collatz_sequence(13));
    assert(871 == longest_collatz_sequence(1000));
    assert(6171 == longest_collatz_sequence(10000));
    assert(77031 == longest_collatz_sequence(100000));
    assert(837799 == longest_collatz_sequence(1000000));

    return 0;
}
