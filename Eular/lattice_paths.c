/**
 * Lattice paths.
 * https://projecteuler.net/problem=15
 */

#include <assert.h>
#include <math.h>

unsigned long long lattice_path(int grid)
{
    double path = 1.0;

    for (int i = 1; i <= grid; i++) {
        path *= ((double) (grid + i) / i);;
    }

    return (unsigned long long) ceil(path);
}

int main()
{
    assert(6 == lattice_path(2));
    assert(252 == lattice_path(5));
    assert(184756 == lattice_path(10));
    assert(155117520 == lattice_path(15));
    assert(137846528820 == lattice_path(20));

    return 0;
}
