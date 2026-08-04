#include <stdlib.h>

int* findMissingElements(int* nums, int numsSize, int* returnSize) {
    int min = 101, max = 0;
    int present[101] = {0};

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < min) min = nums[i];
        if (nums[i] > max) max = nums[i];
        present[nums[i]] = 1;
    }

    int* missing = (int*)malloc((max - min + 1) * sizeof(int));
    int count = 0;

    for (int i = min; i <= max; i++) {
        if (!present[i]) {
            missing[count++] = i;
        }
    }

    *returnSize = count;
    return missing;
}
