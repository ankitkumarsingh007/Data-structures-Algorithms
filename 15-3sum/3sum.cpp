class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        int n = nums.size();

        for (int i = 0; i < n - 2; i++) {
            int sum = -nums[i], l = i + 1, r = n - 1;

            while (l < r) {
                int total = nums[l] + nums[r];
                if (total < sum) {
                    l++;
                } else if (total > sum) {
                    r--;
                } else {
                    res.push_back({nums[i], nums[l], nums[r]});

                    while (l < r && nums[l] == nums[l + 1])
                        l++;
                    while (l < r && nums[r] == nums[r - 1])
                        r--;

                    l++, r--;
                }
            }

            while (i < n - 2 && nums[i] == nums[i + 1])
                i++;
        }

        return res;
    }
};