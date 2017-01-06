#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX_FACTORS 25

typedef struct PRIME_FACTORS
{
  unsigned long *factors;
  unsigned long count;
} Prime_Factor;

Prime_Factor prime_factors(unsigned long n)
{
    int root = (int) sqrt(n);
    unsigned long *factors = (unsigned long *) malloc(MAX_FACTORS * sizeof(unsigned long));

    unsigned long j = 0;
    for (unsigned long i = 2; i <= root; i++) {
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

int main()
{
    unsigned long n;

    printf("%s", "Enter n: ");
    scanf("%lu", &n);

    Prime_Factor factor = prime_factors(n);

    for (int i = 0; i < factor.count; i++) {
        printf("%lu ", factor.factors[i]);
    }

    return 0;
}
