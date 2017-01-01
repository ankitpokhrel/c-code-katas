#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <assert.h>

bool is_prime(int number)
{
    int root = (int) sqrt(number);

    for (int i = 2; i <= root; i++) {
        if (number % i == 0) {
            return false;
        }
    }

    return true;
}

int main()
{
    int primes[] = {2, 3, 7, 11, 13, 17};
    int non_primes[] = {4, 6, 8, 12, 14, 15};

    for (int i = 0; i < 6; i++) {
        assert(is_prime(primes[i]));
        assert(is_prime(non_primes[i]) == false);
    }

    return 0;
}
