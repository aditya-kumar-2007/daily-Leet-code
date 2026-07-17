#include <stdlib.h>

long long choose2(long long x) {
    return x * (x - 1) / 2;
}

int cmp(const void *a, const void *b) {
    long long x = *(long long *)a;
    long long y = *(long long *)b;
    return (x > y) - (x < y);
}

int* gcdValues(int* nums, int numsSize, long long* queries, int queriesSize, int* returnSize) {
    int mx = 0;
    for (int i = 0; i < numsSize; i++)
        if (nums[i] > mx) mx = nums[i];

    int *freq = calloc(mx + 1, sizeof(int));
    for (int i = 0; i < numsSize; i++)
        freq[nums[i]]++;

    long long *exact = calloc(mx + 1, sizeof(long long));

    for (int g = mx; g >= 1; g--) {
        long long cnt = 0;
        for (int j = g; j <= mx; j += g)
            cnt += freq[j];

        exact[g] = choose2(cnt);

        for (int j = g * 2; j <= mx; j += g)
            exact[g] -= exact[j];
    }

    long long *pref = calloc(mx + 1, sizeof(long long));
    for (int g = 1; g <= mx; g++)
        pref[g] = pref[g - 1] + exact[g];

    int *ans = malloc(sizeof(int) * queriesSize);

    for (int i = 0; i < queriesSize; i++) {
        long long k = queries[i] + 1;
        int l = 1, r = mx;
        while (l < r) {
            int mid = (l + r) / 2;
            if (pref[mid] >= k)
                r = mid;
            else
                l = mid + 1;
        }
        ans[i] = l;
    }

    free(freq);
    free(exact);
    free(pref);

    *returnSize = queriesSize;
    return ans;
}