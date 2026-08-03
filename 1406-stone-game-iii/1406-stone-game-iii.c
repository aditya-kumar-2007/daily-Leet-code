#include <limits.h>

char* stoneGameIII(int* s, int n) {
    int dp[4] = {0}, i, k;
    for (i = n - 1; i >= 0; --i) {
        int take = 0, max = INT_MIN;
        for (k = 1; k <= 3 && i + k <= n; ++k) {
            take += s[i + k - 1];
            int gain = take - dp[(i + k) % 4];
            if (gain > max) max = gain;
        }
        dp[i % 4] = max;
    }
    return dp[0] > 0 ? "Alice" : (dp[0] < 0 ? "Bob" : "Tie");
}
