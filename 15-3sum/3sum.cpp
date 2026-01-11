class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> st;

        for (int i = 0; i < nums.size() - 2; i++) {
            int target = -nums[i];
            int l = i + 1, r = nums.size() - 1;

            while (l < r) {
                int sum = nums[l] + nums[r];
                if (sum == target) {
                    st.insert({nums[i], nums[l], nums[r]});
                    while (l < r && nums[l + 1] == nums[l])
                        l++;
                    l++;
                } else if (sum < target)
                    l++;
                else
                    r--;
            }
        }

        vector<vector<int>> res;
        for (auto v : st) {
            res.push_back(v);
        }

        return res;
    }
};