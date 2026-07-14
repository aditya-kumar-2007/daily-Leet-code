#define MOD 1000000007

int gcd(int a, int b) {
    while (b) {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int subsequencePairCount(int* nums, int numsSize) {
    static long long dp[201][201];
    static long long ndp[201][201];

    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;

    for (int i = 0; i < numsSize; i++) {
        memset(ndp, 0, sizeof(ndp));
        int x = nums[i];

        for (int g1 = 0; g1 <= 200; g1++) {
            for (int g2 = 0; g2 <= 200; g2++) {
                long long cur = dp[g1][g2];
                if (!cur) continue;

                ndp[g1][g2] = (ndp[g1][g2] + cur) % MOD;

                int ng1 = (g1 == 0) ? x : gcd(g1, x);
                ndp[ng1][g2] = (ndp[ng1][g2] + cur) % MOD;

                int ng2 = (g2 == 0) ? x : gcd(g2, x);
                ndp[g1][ng2] = (ndp[g1][ng2] + cur) % MOD;
            }
        }

        memcpy(dp, ndp, sizeof(dp));
    }

    long long ans = 0;
    for (int g = 1; g <= 200; g++) {
        ans = (ans + dp[g][g]) % MOD;
    }

    return (int)ans;
}