class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        bool oneExist = false;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1)
                oneExist = true;

            if (nums[i] <= 0 || nums[i] > n)
                nums[i] = 0;
            else
                nums[i]--;
        }

        if (!oneExist)
            return 1;

        for (int i = 0; i < n; i++) {
            nums[nums[i] % n] += n;
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] < n)
                return i + 1;
        }
        return n + 1;
    }
};