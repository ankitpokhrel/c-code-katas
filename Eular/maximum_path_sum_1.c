/**
 * Maximum Path Sum I
 * https://projecteuler.net/problem=18
 */

#include <math.h>
#include <assert.h>

#define MAX_LENGTH 100

int sum_brute_force(int triangle[MAX_LENGTH][MAX_LENGTH], int n)
{
    int possible_routes = (int) pow(2, n - 1);

    int largest = 0, sum, index;

    for (int i = 0; i < possible_routes; i++) {
        sum = triangle[0][0];

        index = 0;
        for (int j = 0; j < n - 1; j++) {
            /**
             * Decide whether to stay at same level or go right.
             *
             * We will check if jth bit is set on index i by right shiftting i jth times
             * and check if first bit for the number is set or not. if we encounter 0 (odd)
             * we stay at same level, if we encounter 1 (even) we go right by 1.
             */
            index += (i >> j & 1);

            /**
             * Right shift expression can be written as i >> j => i / (int) pow(2, j) and
             * Bitwise & can be written as i & j => i % pow(2, j) in mathematical notation.
             *
             * So the above expression is equivalent to
             * index += (i / (int) pow(2, j)) % 2;
             */

            sum += triangle[j + 1][index];
        }

        if (sum > largest) {
            largest = sum;
        }
    }

    return largest;
}

int main()
{
    int test_data_1[MAX_LENGTH][MAX_LENGTH] = {
        {3},
        {7, 4},
        {2, 4, 6},
        {8, 5, 9, 3}
    };

    int test_data_2[MAX_LENGTH][MAX_LENGTH] = {
        {75},
        {95, 64},
        {17, 47, 82},
        {18, 35, 87, 10},
        {20, 4, 82, 47, 65},
        {19, 1, 23, 75, 3, 34},
        {88, 2, 77, 73, 7, 63, 67},
        {99, 65, 4, 28, 6, 16, 70, 92},
        {41, 41, 26, 56, 83, 40, 80, 70, 33},
        {41, 48, 72, 33, 47, 32, 37, 16, 94, 29},
        {53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14},
        {70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57},
        {91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48},
        {63, 66, 4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31},
        {4, 62, 98, 27, 23, 9, 70, 98, 73, 93, 38, 53, 60, 4, 23},
    };

    assert(23 == sum_brute_force(test_data_1, 4));
    assert(1074 == sum_brute_force(test_data_2, 15));

    return 0;
}
