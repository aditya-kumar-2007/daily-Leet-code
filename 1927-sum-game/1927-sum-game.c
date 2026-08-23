bool sumGame(char* num) {
    int n = strlen(num), d = 0, q1 = 0, q2 = 0;

    for (int i = 0; i < n / 2; i++)
        if (num[i] == '?') q1++;
        else d += num[i] - '0';

    for (int i = n / 2; i < n; i++)
        if (num[i] == '?') q2++;
        else d -= num[i] - '0';

    if ((q1 + q2) % 2) return true;

    return d != 9 * (q2 - q1) / 2;
}