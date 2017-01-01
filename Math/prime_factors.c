#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct PRIME_FACTORS
{
  int *factors;
  int count;
} Prime_Factor;

Prime_Factor prime_factors(int n)
{
    int root = (int) sqrt(n);
    int *factors = (int *) malloc((n / 2) * sizeof(int));

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

int main()
{
    int n;

    printf("%s", "Enter n: ");
    scanf("%d", &n);

    Prime_Factor factor = prime_factors(n);

    for (int i = 0; i < factor.count; i++) {
        printf("%d ", factor.factors[i]);
    }

    return 0;
}
