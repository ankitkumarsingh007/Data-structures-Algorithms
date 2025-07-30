class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int val = nums[0], n = nums.size();

        for (int i = 1; i < n; i++) {
            val = max(val, nums[i]);
        }

        int res = 1;
        for (int i = 0; i < n;) {
            if (nums[i] == val) {
                int curr = 1;
                i++;
                while (i < n) {
                    if (nums[i] == nums[i - 1]) {
                        i++;
                        curr++;
                    }else{
                        break;
                    }
                }
                res=max(res,curr);
            } else {
                i++;
            }
        }

        return res;
    }
};