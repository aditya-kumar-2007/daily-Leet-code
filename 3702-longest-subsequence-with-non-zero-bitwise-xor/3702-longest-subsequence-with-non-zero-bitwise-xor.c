int longestSubsequence(int* nums, int numsSize) {
    int x = 0, nz = 0;

    for (int i = 0; i < numsSize; i++) {
        x ^= nums[i];
        if (nums[i] != 0) nz = 1;
    }

    if (x != 0) return numsSize;
    if (nz) return numsSize - 1;
    return 0;
}