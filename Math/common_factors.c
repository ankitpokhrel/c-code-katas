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

int main()
{
    int test_data[3][2] = {
        {54, 27},
        {350, 105},
        {81, 405}
    };

    Factor factors;
    for (int i = 0; i < 3; i++) {
        factors = get_common_factors(test_data[i][0], test_data[i][1]);

        printf("\n%d common factors for (%d, %d): ", factors.count, test_data[i][0], test_data[i][1]);
        for (int k = 0; k < factors.count; k++) {
            printf("%d ", factors.factors[k]);
            assert(test_data[i][0] % factors.factors[k] == 0);
            assert(test_data[i][1] % factors.factors[k] == 0);
        }
    }

    return 0;
}
