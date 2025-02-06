class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int val1 = INT_MAX, val2 = INT_MAX, cnt1 = 0, cnt2 = 0, n = nums.size();

        for (int i = 0; i < n; i++) {
            if (cnt1 == 0 && nums[i] != val2) {
                val1 = nums[i];
                cnt1 = 1;
            } else if (cnt2 == 0 && nums[i] != val1) {
                val2 = nums[i];
                cnt2 = 1;
            } else if (nums[i] == val1)
                cnt1++;
            else if (nums[i] == val2)
                cnt2++;
            else {
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = 0, cnt2 = 0;
        for (int a : nums) {
            if (a == val1)
                cnt1++;
            if (a == val2)
                cnt2++;
        }

        vector<int> res;

        if (cnt1 > n / 3)
            res.push_back(val1);

        if (cnt2 > n / 3)
            res.push_back(val2);

        return res;
    }
};