/**
 * Program to convert number to words and Number letters count.
 * https://projecteuler.net/problem=17
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#define MAX_LETTERS_LENGTH 100

const char LETTERS[20][10] = {
    "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
    "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen",
    "Eighteen", "Nineteen", "Twenty"
};

/**
 * Maps number to respective text.
 *
 * @param int num
 *
 * @return string
 */
char *mapper(int num)
{
    if (num == 0) {
        return "Zero";
    }

    if (num <= 20) {
        return (char *) LETTERS[num - 1];
    }

    switch (num) {
        case 30:
            return "Thirty";

        case 40:
            return "Forty";

        case 50:
            return "Fifty";

        case 60:
            return "Sixty";

        case 70:
            return "Seventy";

        case 80:
            return "Eighty";

        case 90:
            return "Ninety";

        case 100:
            return "Hundred";

        case 1000:
            return "Thousand";

        default:
            return "";
    }
}

/**
 * Determines if we should add 'and'.
 *
 * @param int* arr
 * @param int j
 *
 * @return bool
 */
bool should_add_conjunction(int *arr, int j)
{
    bool flag = false;

    for (int x = j - 1; x >= 0; x--) {
        if (arr[x] != 0) {
            flag = true;
            break;
        }
    }

    return flag;
}

/**
 * Reduce number to array.
 *
 * @param int* arr
 * @param int num
 *
 * @return int
 */
int num_to_array(int *arr, int num)
{
    int digit, i = 0;

    while (num > 0) {
        digit = num % 10;

        arr[i++] = digit;

        num /= 10;
    }

    return i;
}

/**
 * Convert number to words.
 *
 * @param int num
 * @param string separator
 *
 * @return string
 */
char *number_to_words(int num, char *separator)
{
    if (num < 0 || num > 9999) {
        return "Number out of range";
    }

    if (num <= 20) {
        return mapper(num);
    }

    char *word = (char *) malloc(MAX_LETTERS_LENGTH * sizeof(char));
    int place, arr[5], i = num_to_array(arr, num);

    for (int j = i - 1; j >= 0; j--) {
        if (arr[j] == 0) {
            continue;
        }

        place = (int) pow(10, j);

        if (place <= 10) {
            if (j == 0) {
                snprintf(word, MAX_LETTERS_LENGTH, "%s%s", word, mapper(arr[j]));
                break;
            }

            int tens = arr[j] * place;
            int ones = arr[j - 1];

            if ((tens + ones) <= 20) {
                snprintf(word, MAX_LETTERS_LENGTH, "%s%s", word, mapper(tens + ones));
            } else if (ones != 0) {
                snprintf(word, MAX_LETTERS_LENGTH, "%s%s%s%s", word, mapper(tens), separator, mapper(ones));
            } else {
                snprintf(word, MAX_LETTERS_LENGTH, "%s%s", word, mapper(tens));
            }

            --j;
        } else {
            snprintf(word, MAX_LETTERS_LENGTH, "%s%s%s%s", word, mapper(arr[j]), separator, mapper(place));

            if (num == arr[j] * place) {
                return word;
            }

            snprintf(word, MAX_LETTERS_LENGTH, "%s%s", word, separator);

            if (place == 100 && should_add_conjunction(arr, j)) {
                snprintf(word, MAX_LETTERS_LENGTH, "%s%s%s", word, "and", separator);
            }
        }
    }

    return word;
}

/**
 * Count number of letters in given range.
 *
 * @param int start
 * @param int end
 * @param string separator
 *
 * @return int
 */
int range_sum(int start, int end, char *separator)
{
    int sum = 0;
    char *word;

    for (int i = start; i <= end; i++) {
        word = number_to_words(i, separator);
        sum += strlen(word);
    }

    return sum;
}

int main()
{
    int test_data[20] = {
        1, 10, 15, 35, 83, 100, 110, 117, 155, 223, 577, 999,
        1000, 1100, 1222, 5000, 5555, 7654, 70004, 9999
    };

    char *test_string[20] = {
        "One", "Ten", "Fifteen", "Thirty Five", "Eighty Three", "One Hundred", "One Hundred and Ten",
        "One Hundred and Seventeen", "One Hundred and Fifty Five", "Two Hundred and Twenty Three",
        "Five Hundred and Seventy Seven", "Nine Hundred and Ninety Nine", "One Thousand", "One Thousand One Hundred",
        "One Thousand Two Hundred and Twenty Two", "Five Thousand", "Five Thousand Five Hundred and Fifty Five",
        "Seven Thousand Six Hundred and Fifty Four", "Seven Thousand and Four",
        "Nine Thousand Nine Hundred and Ninety Nine"
    };

    char *test_string_2[20] = {
        "One", "Ten", "Fifteen", "Thirty-Five", "Eighty-Three", "One-Hundred", "One-Hundred-and-Ten",
        "One-Hundred-and-Seventeen", "One-Hundred-and-Fifty-Five", "Two-Hundred-and-Twenty-Three",
        "Five-Hundred-and-Seventy-Seven", "Nine-Hundred-and-Ninety-Nine", "One-Thousand", "One-Thousand-One-Hundred",
        "One-Thousand-Two-Hundred-and-Twenty-Two", "Five-Thousand", "Five-Thousand-Five-Hundred-and-Fifty-Five",
        "Seven-Thousand-Six-Hundred-and-Fifty-Four", "Seven-Thousand-and-Four",
        "Nine-Thousand-Nine-Hundred-and-Ninety-Nine"
    };

    for (int i = 0; i < 13; i++) {
        assert(strcmp(test_string[i], number_to_words(test_data[i], " ")) == 0);
        assert(strcmp(test_string_2[i], number_to_words(test_data[i], "-")) == 0);
    }

    assert(36 == range_sum(1, 9, ""));
    assert(70 == range_sum(10, 19, ""));
    assert(748 == range_sum(20, 99, ""));
    assert(20259 == range_sum(100, 999, ""));
    assert(21124 == range_sum(1, 1000, ""));
    assert(152577 == range_sum(1, 5000, ""));

    return 0;
}
