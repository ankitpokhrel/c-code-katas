/**
 * Sum of all multiples of 3 and 5 below 1000
 */
#include <stdio.h>

int sum_multiple_of(int num, int limit)
{
    int sum = num;

    for (int i = num * 2; i < limit; i += num) {
        sum += i;
    }

    return sum;
}

int main()
{
    int limit = 1000, operand_first = 3, operand_second = 5;

    int sum = sum_multiple_of(operand_first, limit) + sum_multiple_of(operand_second, limit) - sum_multiple_of(operand_first * operand_second, limit);

    printf("Sum: %d",  sum);

    return 0;
}
