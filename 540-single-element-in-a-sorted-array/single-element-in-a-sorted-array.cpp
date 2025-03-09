class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int res = 0;
        for (int a : nums) {
            res ^= a;
        }

        return res;
    }
};