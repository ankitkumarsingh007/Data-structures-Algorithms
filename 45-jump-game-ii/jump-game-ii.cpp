class Solution {
public:
    int jump(vector<int>& nums) {
        int res = -1, currReachable = 0, maxReachable = 0;
        for (int i = 0; i < nums.size();) {
            while (i <= currReachable && i < nums.size()) {
                maxReachable = max(maxReachable, i + nums[i]);
                i++;
            }
            currReachable = maxReachable;
            res++;
        }
        return res;
    }
};