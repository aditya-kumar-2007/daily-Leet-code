int uniqueXorTriplets(int* nums, int numsSize) {
    if (numsSize <= 2) {
        return numsSize;
    }
    int bits = 32 - __builtin_clz(numsSize);
    return 1 << bits;
}
