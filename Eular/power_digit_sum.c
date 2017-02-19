/**
 * Power digit sum.
 * https://projecteuler.net/problem=16
 */

#include <stdlib.h>
#include <math.h>
#include <assert.h>

int array_sum(int *arr, int length)
{
    int sum = 0;

    for (int i = 0; i < length; i++) {
        sum = sum + arr[i];
    }

    return sum;
}

int power_digit_sum(int n)
{
    size_t max_required_space = (size_t) ceil(0.35 * n);

    int *power = (int *) calloc(max_required_space, sizeof(int));

    power[0] = 1;

    for (int i = 1; i <= n; i++) {
        power[0] = 2 * power[0];

        for (int k = 1; k < max_required_space; k++) {
            power[k] = 2 * power[k] + power[k - 1] / 10;
        }

        for (int j = 0; j < max_required_space; j++) {
            power[j] = power[j] % 10;
        }
    }

    return array_sum(power, (int) max_required_space);
}

int main()
{
    assert(5 == power_digit_sum(5));
    assert(26 == power_digit_sum(15));
    assert(115 == power_digit_sum(100));
    assert(679 == power_digit_sum(500));
    assert(1366 == power_digit_sum(1000));
    assert(2035 == power_digit_sum(1500));
    assert(2704 == power_digit_sum(2000));
    assert(3871 == power_digit_sum(3000));
}
