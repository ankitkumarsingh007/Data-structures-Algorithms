class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 1, res = nums[0], n = nums.size();

        for (int i = 1; i < n; i++) {
            if (nums[i] == res) {
                cnt++;
            } else {
                cnt--;

                if (cnt == 0) {
                    res = nums[i];
                    cnt = 1;
                }
            }
        }

        return res;
    }
};