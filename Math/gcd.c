#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

typedef struct FACTOR
{
  int *factors;
  int count;
} Factor;

Factor get_common_factors(int a, int b)
{
    int root = (int) sqrt(a);

    int *factors = (int *) malloc((a / 2) * sizeof(int));

    int j = 0;
    for (int i = 1; i <= root; i++) {
        if (a % i == 0) {
            if (b % i == 0) {
                factors[j++] = i;
            }

            int f = a / i;
            if (f != i && b % f == 0) {
                factors[j++] = a / i;
            }
        }
    }

    Factor factor = {
        .factors = factors,
        .count = j
    };

    return factor;
}

int gcd(int a, int b)
{
    Factor common_factors = get_common_factors(a, b);

    int largest = common_factors.factors[0];
    for (int i = 1; i < common_factors.count; i++) {
        if (common_factors.factors[i] > largest) {
            largest = common_factors.factors[i];
        }
    }

    return largest;
}

int main()
{
    assert(6 == gcd(888, 78));
    assert(5 == gcd(45, 25));
    assert(2 == gcd(142, 872));
    assert(111 == gcd(999, 111));
    assert(250 == gcd(4500, 1250));

    return 0;
}
