#include <assert.h>

int euclid_gcd(int dividend, int divisor)
{
    while (divisor != 0) {
        int remainder = dividend % divisor;

        dividend = divisor;
        divisor = remainder;
    }

    return dividend;
}

int euclid_gcd_recursive(int dividend, int divisor)
{
    return divisor == 0 ? dividend : euclid_gcd_recursive(divisor, dividend % divisor);
}

int main()
{
    assert(6 == euclid_gcd(888, 78));
    assert(5 == euclid_gcd(45, 25));
    assert(2 == euclid_gcd(142, 872));
    assert(111 == euclid_gcd(999, 111));
    assert(250 == euclid_gcd(4500, 1250));

    assert(6 == euclid_gcd_recursive(888, 78));
    assert(5 == euclid_gcd_recursive(45, 25));
    assert(2 == euclid_gcd_recursive(142, 872));
    assert(111 == euclid_gcd_recursive(999, 111));
    assert(250 == euclid_gcd_recursive(4500, 1250));

    return 0;
}
