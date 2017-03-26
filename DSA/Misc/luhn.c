/**
 * The Luhn algorithm or Luhn formulam is a simple checksum formula
 * used to validate a variety of identification numbers, such as
 * credit card numbers, IMEI numbers etc.
 *
 * https://en.wikipedia.org/wiki/Luhn_algorithm
 */

#include <string.h>
#include <stdlib.h>
#include <assert.h>

int *get_array(char *str, int len)
{
    int *arr = (int *) malloc(len * sizeof(int));

    for (int i = 0; i < len; i++) {
        arr[i] = str[i] - '0';
    }

    return arr;
}

int array_sum(int *arr, int len)
{
    int sum = 0;
    for (int i = 0; i < len; i++) {
        sum += arr[i];
    }

    return sum;
}

int luhn_check_sum(char *str)
{
    int len = (int) strlen(str);

    int *arr = get_array(str, len);

    for (int i = len - 1; i >= 0; i -= 2) {
        int multiple = arr[i] * 2;

        if (multiple > 9) {
            multiple -= 9;
        }

        arr[i] = multiple;
    }

    int sum = array_sum(arr, len);

    return sum * 9 % 10;
}

int main()
{
    char *test_card_numbers[] = {
        "601100099013942", "37828224631000",
        "37144963539843", "555555555555444",
        "501971701010374", "552263411203590"
    };

    int check_bits[] = {4, 5, 1, 4, 2, 6};

    for (int i = 0; i < 6; i++) {
        assert(check_bits[i] == luhn_check_sum(test_card_numbers[i]));
    }

    return 0;
}
