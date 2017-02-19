/**
 * Smallest multiple.
 * https://projecteuler.net/problem=5
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#define MAX_FACTORS 25

typedef struct PRIME_FACTORS
{
  int *factors;
  int count;
} Prime_Factor;

/**
 * Find prime factors of a given number.
 *
 * @param int n
 *
 * @return struct PRIME_FACTORS
 */
Prime_Factor prime_factors(int n)
{
    int root = (int) sqrt(n);
    int *factors = (int *) malloc(MAX_FACTORS * sizeof(int));

    int j = 0;
    for (int i = 2; i <= root; i++) {
        if (n % i == 0) {
            while (n % i == 0) {
                n = n / i;
                factors[j++] = i;
            }
        }
    }

    if (n != 1) {
        factors[j++] = n;
    }

    Prime_Factor factor = {
        .factors = factors,
        .count = j
    };

    return factor;
}

/**
 * Find if a value is in array.
 *
 * @param int needle
 * @param int[] haystack
 * @param int length
 * @return int Index if found else -1
 */
int in_array(int needle, int *haystack, int length)
{
    for (int i = 0; i < length; i++) {
        if (needle == haystack[i]) {
            return i;
        }
    }

    return -1;
}

/**
 * Count number of occurrence given number
 * in an array.
 *
 * @param int needle
 * @param int[] haystack
 * @param int length
 *
 * @return int
 */
int count_in_array(int needle, int *haystack, int length)
{
    int count = 0;

    for (int i = 0; i < length; i++) {
        if (needle == haystack[i]) {
            ++count;
        }
    }

    return count;
}

/**
 * Calculate smallest multiple evenly divisible
 * up to given number.
 *
 * @param num
 *
 * @return unsigned long long
 */
unsigned long long smallest_multiple(int num)
{
    Prime_Factor factor;

    int k = 0, l;
    int pf[MAX_FACTORS];
    int count[MAX_FACTORS];
    int *processed;

    for (int i = num; i > 1; i--) {
        factor = prime_factors(i);

        l = 0;
        processed = (int *) calloc((size_t) factor.count, sizeof(int));
        for (int j = 0; j < factor.count; j++) {
            if (in_array(factor.factors[j], processed, l) != -1) {
                break;
            }

            processed[l++] = factor.factors[j];

            int factor_index = in_array(factor.factors[j], pf, k);
            int factor_count = count_in_array(factor.factors[j], factor.factors, factor.count);

            if (factor_index == -1) {
                pf[k] = factor.factors[j];
                count[k++] = factor_count;
            } else if (count[factor_index] < factor_count) {
                count[factor_index] += (factor_count - count[factor_index]);
            }
        }

        free(processed);
    }

    unsigned long long multiple = 1;
    for (int m = 0; m < k; m++) {
        multiple *= pow(pf[m], count[m]);
    }

    return multiple;
}

/**
 * Efficient way to calculate smallest multiple
 * evenly divisible up to given number.
 *
 * @param num
 *
 * @return unsigned long long
 */
unsigned long long smallest_multiple_efficient(int num)
{
    unsigned long long multiple = 1;

    int limit = (int) sqrt(num);
    bool check = true;

    int primes[MAX_FACTORS] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
    int count[MAX_FACTORS];

    int i = 0;
    while (primes[i] <= num) {
        count[i] = 1;
        if (check) {
            if (primes[i] <= limit) {
                count[i] = (int) floor(log(num) / log(primes[i]));
            } else {
                check = false;
            }
        }

        multiple *= pow(primes[i], count[i]);

        i++;
    }

    return multiple;
}

int main()
{
    assert(60 == smallest_multiple(5));
    assert(2520 == smallest_multiple(10));
    assert(232792560 == smallest_multiple(20));
    assert(2329089562800 == smallest_multiple(30));

    assert(60 == smallest_multiple_efficient(5));
    assert(2520 == smallest_multiple_efficient(10));
    assert(232792560 == smallest_multiple_efficient(20));
    assert(2329089562800 == smallest_multiple_efficient(30));

    return 0;
}
