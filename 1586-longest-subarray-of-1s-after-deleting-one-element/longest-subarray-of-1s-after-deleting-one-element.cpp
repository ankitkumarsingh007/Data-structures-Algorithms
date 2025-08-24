class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int res = 0, part1 = 0, part2 = 0, n = nums.size();
        bool foundMidZero = false, anyzero = false;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                if (i == 0 || nums[i - 1] == 0) {
                    part1 = 0, part2 = 0;
                    foundMidZero = false;
                } else {
                    if (part2 != 0) {
                        part1 = part2;
                        part2 = 0;
                    }
                    foundMidZero = true;
                }
                anyzero = true;
            } else {
                if (!foundMidZero) {
                    part1++;
                } else {
                    part2++;
                }
            }
            res = max(res, part1 + part2);
        }

        return anyzero ? res : n-1;
    }
};