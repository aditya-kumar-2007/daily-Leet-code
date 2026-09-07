class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        unordered_map<int, int> m;
        m[0] = 1;
        int s = 0, c=0;
        for(int n : nums){
            s += n;
            if(m.count(s - k)) c +=m[s - k];
            m[s]++;

        }
        return c;
    }

};