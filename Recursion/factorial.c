#include <assert.h>

long long factorial(int n)
{
    if (n < 2) {
        return n;
    }

    return n * factorial(n - 1);
}

int main()
{
    assert(2 == factorial(2));
    assert(6 == factorial(3));
    assert(120 == factorial(5));
    assert(3628800 == factorial(10));
    assert(1307674368000 == factorial(15));
    assert(2432902008176640000 == factorial(20));

    return 0;
}
