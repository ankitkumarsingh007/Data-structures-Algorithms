class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        vector<vector<int>> arr(32);
        int n = nums.size();

        for (int j = 0; j < n; j++) {
            long a = nums[j], curr;
            for (int i = 0; i < 32; i++) {
                if (i == 0)
                    curr = 1;
                else
                    curr *= 2;
                if (a & curr) {
                    arr[i].push_back(j);
                }
            }
        }

        vector<int> res;
        for (int i = 0; i < n; i++) {
            int val = 1;
            long a = nums[i], curr;
            for (int j = 0; j < 32; j++) {
                if (j == 0)
                    curr = 1;
                else
                    curr *= 2;
                if (a & curr)
                    continue;
                else {
                    auto it = upper_bound(arr[j].begin(), arr[j].end(), i);
                    if (it != arr[j].end())
                        val = max(val, *it - i + 1);
                }
            }
            res.push_back(val);
        }

        return res;
    }
};