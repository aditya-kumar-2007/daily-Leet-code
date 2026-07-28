#include <stdlib.h>
#include <string.h>

char* smallestPalindrome(char* s) {
    int c[26] = {0}, i, j = 0, n = strlen(s);

    for (i = 0; s[i]; i++)
        c[s[i] - 'a']++;

    char *a = (char *)malloc(n + 1);
    char *r = (char *)malloc(n / 2 + 1);

    int k = 0, m = -1;

    for (i = 0; i < 26; i++) {
        while (c[i] > 1) {
            r[k++] = i + 'a';
            c[i] -= 2;
        }
        if (c[i])
            m = i;
    }

    for (i = 0; i < k; i++)
        a[j++] = r[i];

    if (m != -1)
        a[j++] = m + 'a';

    for (i = k - 1; i >= 0; i--)
        a[j++] = r[i];

    a[j] = '\0';

    free(r);
    return a;
}