/**
 * Special pythagorean triplet.
 * https://projecteuler.net/problem=9
 */

#include <assert.h>

unsigned long long pythagorean(int a, int b)
{
    return (unsigned long long) a * a + b * b;
}

/**
 * a^2 + b^2 = (s-a-b)^2  where a < b < c
 *
 * @param int limit
 *
 * @return
 */
unsigned long long product_pythagorean_triplet(int limit)
{
    for (int a = 3; a < (limit - 3) / 3; a++) {
        for (int b = a + 1; b < (limit - a - 1) / 2; b++) {
            int c = limit - a - b;
            if (c * c == pythagorean(a, b)) {
                return (unsigned long long) a * b * c;
            }
        }
    }

    return 0;
}

int main()
{
    assert(12180 == product_pythagorean_triplet(70));
    assert(31875000 == product_pythagorean_triplet(1000));
    assert(31875000000 == product_pythagorean_triplet(10000));

    return 0;
}
