#include <stdbool.h>

bool isMatch(char *s, char *p) {
    if (!*p) return !*s;

    bool first = *s && (*p == *s || *p == '.');

    if (*(p + 1) == '*')
        return isMatch(s, p + 2) || (first && isMatch(s + 1, p));

    return first && isMatch(s + 1, p + 1);
}