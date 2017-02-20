#include <stdbool.h>
#include <assert.h>

bool is_palindrome(char *str, int index, int size)
{
    if (index > size / 2) {
        return true;
    }

    if (str[index] != str[size - index]) {
        return false;
    }

    return is_palindrome(str, index + 1, size);
}

int main()
{
    assert(!is_palindrome("ankit", 0, 4));
    assert(!is_palindrome("lirxil", 0, 5));
    assert(!is_palindrome("kaayak", 0, 5));
    assert(!is_palindrome("ka ya k", 0, 6));
    assert(!is_palindrome("namasman", 0, 7));

    assert(is_palindrome("liril", 0, 4));
    assert(is_palindrome("kayak", 0, 4));
    assert(is_palindrome("racecar", 0, 6));
    assert(is_palindrome("rotator", 0, 6));
    assert(is_palindrome("rottaattor", 0, 9));

    return 0;
}
