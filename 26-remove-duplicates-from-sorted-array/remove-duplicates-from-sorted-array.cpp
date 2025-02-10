class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(), k = 1;

        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[k - 1]) {
                swap(nums[k++], nums[i]);
            }
        }

        return k;
    }
};