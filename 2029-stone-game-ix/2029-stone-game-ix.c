bool stoneGameIX(int* stones, int n) {
    int c[3] = {0};

    for (int i = 0; i < n; i++)
        c[stones[i] % 3]++;

    if (c[1] == 0 || c[2] == 0)
        return (c[1] > 2 || c[2] > 2) && c[0] % 2;

    return abs(c[1] - c[2]) > 2 || c[0] % 2 == 0;
}