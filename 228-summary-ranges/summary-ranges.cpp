class Solution {
public:
    string range(int a) { return to_string(a); }
    string range(int a, int b) { return to_string(a) + "->" + to_string(b); }

    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (i == (n - 1) || nums[i + 1] != (nums[i] + 1)) {
                res.push_back(range(nums[i]));
            } else {
                int j = i + 1;
                while (j < (n - 1) && nums[j + 1] == (nums[j] + 1)) {
                    j++;
                }
                res.push_back(range(nums[i], nums[j]));
                i = j;
            }
        }

        return res;
    }
};