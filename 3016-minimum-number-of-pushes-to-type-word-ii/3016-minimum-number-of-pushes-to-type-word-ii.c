int cmp(const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}

int minimumPushes(char *word) {
    int f[26] = {0}, ans = 0;

    while (*word)
        f[*word++ - 'a']++;

    qsort(f, 26, sizeof(int), cmp);

    for (int i = 0; i < 26 && f[i]; i++)
        ans += f[i] * (i / 8 + 1);

    return ans;
}