long long gcd(long long a, long long b) {
    while (b) {
        long long t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

long long gcdSum(int* nums, int numsSize) {
    int *prefixGcd = (int *)malloc(numsSize * sizeof(int));
    int mx = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > mx)
            mx = nums[i];
        prefixGcd[i] = (int)gcd(nums[i], mx);
    }

    qsort(prefixGcd, numsSize, sizeof(int), cmp);

    long long ans = 0;
    int i = 0, j = numsSize - 1;

    while (i < j) {
        ans += gcd(prefixGcd[i], prefixGcd[j]);
        i++;
        j--;
    }

    free(prefixGcd);
    return ans;
}