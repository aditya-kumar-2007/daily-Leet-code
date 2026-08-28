class Solution:
    def sortedSquares(self, nums):
        n = len(nums)
        ans = [0] * n
        l, r = 0, n - 1

        for i in range(n - 1, -1, -1):
            if abs(nums[l]) > abs(nums[r]):
                ans[i] = nums[l] ** 2
                l += 1
            else:
                ans[i] = nums[r] ** 2
                r -= 1

        return ans