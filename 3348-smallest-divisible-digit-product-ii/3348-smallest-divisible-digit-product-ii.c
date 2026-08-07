#include <stdlib.h>
#include <string.h>

int F[10][4] = {{0},{0},{1},{0,1},{2},{0,0,1},{1,1},{0,0,0,1},{3},{0,2}}, P[] = {2, 3, 5, 7};

int GL(int *r, int *d) {
    int v[4], s = 0; memcpy(v, r, 16); memset(d, 0, 40);
    d[9] = v[1] / 2; v[1] %= 2; d[8] = v[0] / 3; v[0] %= 3; d[7] = v[3];
    if (v[1] && v[0]) { d[6] = 1; v[1]--; v[0]--; }
    d[5] = v[2]; d[4] = v[0] / 2; v[0] %= 2; d[3] = v[1]; d[2] = v[0];
    for (int i = 2; i <= 9; i++) s += d[i]; return s;
}

char* BD(char *num, int len, int p, int d, int *dig, int rl) {
    char *res = malloc(len + 1); if (p >= 0) { strncpy(res, num, p); res[p] = '0' + d; }
    int idx = p + 1, ones = (len - 1 - p) - rl; while (ones-- > 0) res[idx++] = '1';
    for (int i = 2; i <= 9; i++) while (dig[i]--) res[idx++] = '0' + i;
    res[len] = 0; return res;
}

char* smallestNumber(char* num, long long t) {
    int T[4] = {0}, C[4] = {0}, D[10], n = strlen(num), fz = -1, ok = 1;
    for (int i = 0; i < 4; i++) while (t % P[i] == 0) { T[i]++; t /= P[i]; }
    if (t > 1) return "-1";
    for (int i = 0; i < n; i++) {
        if (num[i] == '0' && fz == -1) fz = i;
        if (fz == -1) for (int j = 0; j < 4; j++) C[j] += F[num[i]-'0'][j];
    }
    if (fz == -1) {
        for (int j = 0; j < 4; j++) if (C[j] < T[j]) ok = 0;
        if (ok) return strdup(num);
    }
    for (int i = (fz != -1 ? fz : n - 1); i >= 0; i--) {
        int sd = num[i] - '0' + 1, R[4];
        if (num[i] != '0' && (fz == -1 || i < fz)) for (int j = 0; j < 4; j++) C[j] -= F[num[i]-'0'][j];
        for (int d = sd; d <= 9; d++) {
            for (int j = 0; j < 4; j++) { int g = C[j] + F[d][j]; R[j] = T[j] > g ? T[j] - g : 0; }
            int rl = GL(R, D); if (rl <= n - 1 - i) return BD(num, n, i, d, D, rl);
        }
    }
    int rl = GL(T, D), fl = rl > n + 1 ? rl : n + 1; return BD(num, fl, -1, 0, D, rl);
}
