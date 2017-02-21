#include <assert.h>

unsigned long long ackermann(unsigned int m, unsigned long long n)
{
    if (m == 0) {
        return n + 1;
    }

    if (n == 0) {
        return ackermann(m - 1, 1);
    }

    return ackermann(m - 1, ackermann(m, n - 1));
}

int main()
{
    assert(2 == ackermann(1, 0));
    assert(11 == ackermann(2, 4));
    assert(13 == ackermann(3, 1));
    assert(125 == ackermann(3, 4));
    assert(65533 == ackermann(4, 1));

    return 0;
}
