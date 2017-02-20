#include <string.h>
#include <assert.h>

/**
 * Replace char ch with given character in a string.
 *
 * @param char* str
 * @param char ch Character to replace
 * @param char with Replacing character
 * @param int index Current index
 *
 * return void
 */
void char_replace(char *str, char ch, char with, int index)
{
    if (str[index] == '\0') {
        return;
    }

    if (str[index] == ch) {
        str[index] = with;
    }

    char_replace(str, ch, with, index + 1);
}

int main()
{
    char test_str[7][120] = {
        "ankit", "ankit pokhrel", "namaste", "This is a crazy world!", "C programming language",
        "Lorem ipsum dolor sit amet, consectetur adipiscing elit.",
        "Pellentesque varius, lorem id consequat elementum, elit dolor suscipit neque, vel rhoncus turpis est vitae lacus."
    };

    char test_replace[7][2] = {
        {'n', 'e'}, {'k', 'x'}, {'a', 'p'}, {'i', 'q'},
        {'m', 'z'}, {'m', 'y'}, {'e', 'x'}
    };

    char expected_output[7][120] = {
        "aekit", "anxit poxhrel", "npmpste", "Thqs qs a crazy world!", "C prograzzing language",
        "Lorey ipsuy dolor sit ayet, consectetur adipiscing elit.",
        "Pxllxntxsqux varius, lorxm id consxquat xlxmxntum, xlit dolor suscipit nxqux, vxl rhoncus turpis xst vitax lacus."
    };

    for (int i = 0; i < 7; i++) {
        char_replace(test_str[i], test_replace[i][0], test_replace[i][1], 0);

        assert(strcmp(expected_output[i], test_str[i]) == 0);
    }

    return 0;
}
