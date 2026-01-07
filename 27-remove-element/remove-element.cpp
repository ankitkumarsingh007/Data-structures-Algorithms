class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0, k = nums.size();

        for (int i = 0; i < k;) {
            if (nums[i] == val) {
                swap(nums[i], nums[k - 1]);
                k--;
            } else {
                i++;
            }
        }

        return k;
    }
};