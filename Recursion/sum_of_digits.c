#include <assert.h>

long long sum_of_digits(long long n)
{
    if (n <= 0) {
        return 0;
    }

    return (n % 10) + sum_of_digits(n / 10);
}

int main()
{
    assert(1 == sum_of_digits(1));
    assert(3 == sum_of_digits(12));
    assert(6 == sum_of_digits(123));
    assert(15 == sum_of_digits(12345));
    assert(45 == sum_of_digits(123456789));
    assert(59 == sum_of_digits(12345678959));

    return 0;
}
