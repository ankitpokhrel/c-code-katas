/**
 * Largest product in a series.
 * https://projecteuler.net/problem=8
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define NUMBER_LENGTH 1000

/**
 * Get product of digits of numeric string.
 *
 * @param char num
 *
 * @return unsigned long long
 */
unsigned long long get_product(char num[])
{
    unsigned long long product = 1;
    size_t length = strlen(num);

    for (int i = 0; i < length; i++) {
        product *= (num[i] - '0');
    }

    return product;
}

/**
 * Get substring from a given string.
 *
 * @param char[] string
 * @param int start
 * @param int end
 *
 * @return char * Substring
 */
char *substr(char str[], int start, int end)
{
    char *buffer = (char *) malloc((end - start) + 1 * sizeof(char));

    int k = 0;
    for (int j = start; j < end; j++) {
        buffer[k++] = str[j];
    }
    buffer[k] = '\0';

    return buffer;
}

/**
 * Calculate largest product in a series.
 *
 * @param char number
 * @param int product_length
 *
 * @return unsigned long long Largest product
 */
unsigned long long largest_product_in_series(char number[], int product_length)
{
    unsigned long long largest = 0;
    for (int i = 0; i < NUMBER_LENGTH; i += 1) {
        char *buffer = substr(number, i, i + product_length);

        unsigned long long product = get_product(buffer);

        if (product > largest) {
            largest = product;
        }

        free(buffer);
    }

    return largest;
}

int main()
{
    char number[] = "73167176531330624919225119674426574742355349194934"
        "96983520312774506326239578318016984801869478851843"
        "85861560789112949495459501737958331952853208805511"
        "12540698747158523863050715693290963295227443043557"
        "66896648950445244523161731856403098711121722383113"
        "62229893423380308135336276614282806444486645238749"
        "30358907296290491560440772390713810515859307960866"
        "70172427121883998797908792274921901699720888093776"
        "65727333001053367881220235421809751254540594752243"
        "52584907711670556013604839586446706324415722155397"
        "53697817977846174064955149290862569321978468622482"
        "83972241375657056057490261407972968652414535100474"
        "82166370484403199890008895243450658541227588666881"
        "16427171479924442928230863465674813919123162824586"
        "17866458359124566529476545682848912883142607690042"
        "24219022671055626321111109370544217506941658960408"
        "07198403850962455444362981230987879927244284909188"
        "84580156166097919133875499200524063689912560717606"
        "05886116467109405077541002256983155200055935729725"
        "71636269561882670428252483600823257530420752963450";

    assert(5832 == largest_product_in_series(number, 4));
    assert(2571912 == largest_product_in_series(number, 7));
    assert(23514624000 == largest_product_in_series(number, 13));
    assert(282293061120 == largest_product_in_series(number, 15));

    return 0;
}
