#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int maximumProduct(int* nums, int numsSize)
{
    qsort(nums, numsSize, sizeof(int), cmp);

    int a = nums[0] * nums[1] * nums[numsSize - 1];
    int b = nums[numsSize - 1] * nums[numsSize - 2] * nums[numsSize - 3];

    return a > b ? a : b;
}