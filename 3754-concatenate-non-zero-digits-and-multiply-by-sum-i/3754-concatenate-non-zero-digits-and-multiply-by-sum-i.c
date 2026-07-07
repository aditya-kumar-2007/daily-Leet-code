long long sumAndMultiply(int n) {
    if (n == 0)
        return 0;

    int digits[10];
    int count = 0;

    while (n > 0) {
        int digit = n % 10;
        if (digit != 0)
            digits[count++] = digit;
        n /= 10;
    }

    long long x = 0;
    int sum = 0;

    for (int i = count - 1; i >= 0; i--) {
        x = x * 10 + digits[i];
        sum += digits[i];
    }

    return x * sum;
}