class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int val = nums[0], cnt = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (val == nums[i]) {
                cnt++;
            } else {
                cnt--;
                if (cnt == 0) {
                    val = nums[i];
                    cnt = 1;
                }
            }
        }

        return val;
    }
};