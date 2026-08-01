#include <stdbool.h>

bool predictTheWinner(int* nums, int numsSize) {
    int dp[20] = {0};
    for (int i = 0; i < numsSize; i++) dp[i] = nums[i];

    for (int len = 2; len <= numsSize; len++) {
        for (int i = 0; i <= numsSize - len; i++) {
            int j = i + len - 1;
            dp[i] = (nums[i] - dp[i + 1] > nums[j] - dp[i]) ? nums[i] - dp[i + 1] : nums[j] - dp[i];
        }
    }
    return dp[0] >= 0;
}
