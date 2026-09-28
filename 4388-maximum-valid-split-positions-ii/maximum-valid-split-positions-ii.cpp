class Solution {
public:
    // Remove nums[skip] and count the positions where:
    // GCD(prefix) == GCD(suffix)
    //
    // Key observation:
    // Adding more elements to a set can never increase its GCD.
    // Therefore, while scanning possible split points, we only need to
    // consider positions where the prefix GCD actually changes.
    int getVal(vector<int>& nums, int skip) {
        int n = nums.size();

        // Build the array after removing nums[skip].
        vector<int> arr;
        for (int i = 0; i < n; i++) {
            if (i != skip) {
                arr.push_back(nums[i]);
            }
        }

        int m = arr.size();

        // pre[i] = GCD of arr[0 ... i-1]
        // suf[i] = GCD of arr[i ... m-1]
        vector<int> pre(m, 0);
        vector<int> suf(m, 0);

        // Build prefix GCD.
        for (int i = 1; i < m; i++) {
            pre[i] = gcd(pre[i - 1], arr[i - 1]);
        }

        // Build suffix GCD.
        for (int i = m - 1; i >= 0; i--) {
            if (i == m - 1) {
                suf[i] = arr[i];
            } else {
                suf[i] = gcd(suf[i + 1], arr[i]);
            }
        }

        int count = 0;

        // Check every possible split.
        for (int i = 0; i < m; i++) {
            if (pre[i] == suf[i]) {
                count++;
            }
        }

        return count;
    }

    int maxValidSplits(vector<int>& nums) {
        int n = nums.size();

        // pre[i] = GCD of nums[0 ... i-1]
        vector<int> pre(n + 1, 0);

        for (int i = 1; i < n; i++) {
            pre[i] = gcd(pre[i - 1], nums[i - 1]);
        }

        int res = 0;

        // Try removing one element before checking the splits.
        //
        // Since GCD can only stay the same or decrease as we add elements,
        // removing an element is useful only when it can actually change
        // the prefix GCD.
        //
        // Therefore, we skip positions where:
        //     pre[i] == pre[i - 1]
        //
        // There can be only a small number of distinct decreasing GCD
        // values (roughly O(log(max(nums)))), so getVal() is called only
        // a limited number of times.
        for (int i = 0; i <= n; i++) {

            // If adding nums[i - 1] did not change the prefix GCD,
            // removing it cannot improve the prefix GCD.
            if (i > 0 && pre[i] == pre[i - 1]) {
                continue;
            }

            // For i = 0, there is no element before the split,
            // so use -1 to indicate that no element is removed.
            //
            // For i > 0, remove nums[i - 1].
            res = max(res, getVal(nums, i - 1));
        }

        return res;
    }
};