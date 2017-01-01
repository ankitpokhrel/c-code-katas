#include <stdio.h>
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

int main()
{
    int n;
    Factor factors;

    printf("%s", "Enter n: ");
    scanf("%d", &n);

    factors = get_factors(n);

    printf("Total factors: %d\n", factors.count);
    for (int i = 0; i < factors.count; i++) {
        printf("%d ", factors.factors[i]);
        assert((n % factors.factors[i]) == 0);
    }

    return 0;
}
