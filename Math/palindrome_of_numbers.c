#include <stdbool.h>
#include <assert.h>

/**
 * Check if a number is palindrome.
 *
 * @param unsigned long long num
 *
 * @return bool
 */
bool is_palindrome(unsigned long long num)
{
    int digit;
    unsigned long long n = num;
    unsigned long long reverse = 0;

    while (n > 0) {
        digit = (int) (n % 10);
        reverse = reverse * 10 + digit;
        n /= 10;
    }

    return num == reverse;
}

/**
 * Find largest palindrome made from the product
 * of two n-digit numbers.
 *
 * @param int digit
 *
 * @return unsigned long long
 */
unsigned long long largest_palindrome(int digit)
{
    int first_digit = digit / 10;
    unsigned long long multiple = 0;
    unsigned long long largest = 0;

    for (int i = digit - 1; i >= first_digit; i--) {
        for (int j = digit - 1; j >= i; j--) {
            multiple = (unsigned long long) i * j;
            if (multiple < largest) {
                break;
            }

            if (is_palindrome(multiple)) {
                largest = multiple;
            }
        }
    }

    return largest;
}

int main(void)
{
    unsigned long long palindromes[] = {0, 11, 121, 10201, 9009, 12321};
    unsigned long long non_palindromes[] = {12, 123, 11210, 9109, 12345};

    for (int i = 0; i < 6; i++) {
        assert(is_palindrome(palindromes[i]));
        assert(is_palindrome(non_palindromes[i]) == false);
    }

    assert(9009 == largest_palindrome(100));
    assert(222222 == largest_palindrome(500));
    assert(906609 == largest_palindrome(1000));
    assert(99000099 == largest_palindrome(10000));
    assert(9966006699 == largest_palindrome(100000));

    return 0;
}
