class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_current = nums[0];
        int max_globle = nums[0];
        
        for(size_t i = 1; i < nums.size(); ++i){
            max_current = std::max(nums[i], max_current + nums[i]);
            if(max_current > max_globle){
                max_globle = max_current;
            }
        }
        return max_globle;
    }
};
