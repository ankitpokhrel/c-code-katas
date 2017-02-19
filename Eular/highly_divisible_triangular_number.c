/**
 * Highly divisible traingular number.
 * https://projecteuler.net/problem=12
 */

#include <math.h>
#include <stdlib.h>
#include <assert.h>

typedef struct FACTOR
{
  int *factors;
  int count;
} Factor;

Factor get_factors(int n)
{
    int root = (int) sqrt(n);

    int *factors = (int *) malloc((n / 2) * sizeof(int));

    int j = 0;
    for (int i = 1; i <= root; i++) {
        if (n % i == 0) {
            factors[j++] = i;
            if (i != (n / i)) {
                factors[j++] = n / i;
            }
        }
    }

    Factor factor = {
        .factors = factors,
        .count = j
    };

    return factor;
}

unsigned long highly_divisible_triangular_number(int divisors)
{
    int factorCount = 0;
    unsigned long triangularNumber = 1;

    Factor factor;

    unsigned long i = 1;
    while (factorCount <= divisors) {
        factor = get_factors((int) triangularNumber);

        factorCount = factor.count;

        triangularNumber += (++i);

        free(factor.factors);
    }

    return triangularNumber - i;
}

int main()
{
    assert(28 == highly_divisible_triangular_number(5));
    assert(73920 == highly_divisible_triangular_number(100));
    assert(76576500 == highly_divisible_triangular_number(500));

    return 0;
}
