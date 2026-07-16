char* addBinary(char* a, char* b) {
    int n = strlen(a);
    int m = strlen(b);
    int size = (n > m ? n : m) + 2;

    char *res = (char *)malloc(size);
    int i = n - 1, j = m - 1, k = size - 2;
    int carry = 0;

    res[size - 1] = '\0';

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;

        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';

        res[k--] = (sum % 2) + '0';
        carry = sum / 2;
    }

    k++;

    char *ans = (char *)malloc(size - k);
    strcpy(ans, res + k);
    free(res);

    return ans;
}