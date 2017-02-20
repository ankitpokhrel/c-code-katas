#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

char *substr(char *, size_t);

/**
 * Solution 1: By swapping elements.
 * Will override given string.
 *
 * @param char* str
 * @param int index
 * @param int size
 *
 * @return void
 */
void str_reverse_1(char *str, int index, int size)
{
    if (index == size / 2) {
        return;
    }

    char temp = str[index];
    str[index] = str[size - index];
    str[size - index] = temp;

    str_reverse_1(str, index + 1, size);
}

/**
 * Solution 2: By using temporary var.
 *
 * @param char* str
 *
 * @return char* reversed string
 */
char *str_reverse(char *str)
{
    size_t len = strlen(str);

    static char *reverse = "";
    static int i = 0;

    if (i == 0) {
        reverse = (char *) malloc(len * sizeof(char));
    }

    if (len < 1) {
        reverse[i] = '\0';
        i = 0;

        return reverse;
    }

    reverse[i++] = str[len - 1];

    return str_reverse(substr(str, len));
}

/**
 * Get substring of given length.
 *
 * @param char* str
 * @param size_t len
 *
 * @return char*
 */
char *substr(char *str, size_t len)
{
    char *temp = (char *) malloc(len * sizeof(char));

    strncpy(temp, str, len - 1);
    temp[len - 1] = '\0';

    return temp;
}

int main()
{
    assert(strcmp("a", str_reverse("a")) == 0);
    assert(strcmp("tikna", str_reverse("ankit")) == 0);
    assert(strcmp("lerhkop tikna", str_reverse("ankit pokhrel")) == 0);
    assert(strcmp(".egaugnaL gnimmargorP C", str_reverse("C Programming Language.")) == 0);
    assert(strcmp("!dlrow yzarc a si sihT", str_reverse("This is a crazy world!")) == 0);
    assert(strcmp(
        ".tile gnicsipida rutetcesnoc ,tema tis rolod muspi meroL",
        str_reverse("Lorem ipsum dolor sit amet, consectetur adipiscing elit.")
    ) == 0);

    char s[20] = "ankit";
    str_reverse_1(s, 0, (int) strlen(s) - 1);
    assert(strcmp("tikna", s) == 0);

    strcpy(s, "ankit pokhrel");
    str_reverse_1(s, 0, (int) strlen(s) - 1);
    assert(strcmp("lerhkop tikna", s) == 0);

    return 0;
}
