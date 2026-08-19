#include <stdlib.h>

int cmp(const void *a, const void *b) {
    int *x = *(int **)a, *y = *(int **)b;
    return x[0] - y[0];
}

int maxNumberOfFamilies(int n, int** a, int m, int* c) {
    qsort(a, m, sizeof(int *), cmp);

    long long ans = 2LL * n;

    for (int i = 0; i < m; ) {
        int row = a[i][0];
        int l = 1, mid = 1, r = 1;

        while (i < m && a[i][0] == row) {
            int s = a[i][1];

            if (s >= 2 && s <= 5) l = 0;
            if (s >= 4 && s <= 7) mid = 0;
            if (s >= 6 && s <= 9) r = 0;

            i++;
        }

        if (l && r) continue;
        if (l || mid || r) ans--;
        else ans -= 2;
    }

    return (int)ans;
}