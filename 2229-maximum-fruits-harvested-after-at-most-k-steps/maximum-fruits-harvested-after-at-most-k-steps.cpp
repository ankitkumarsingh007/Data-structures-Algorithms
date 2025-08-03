class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        int maxValue = fruits[n - 1][0] + 1;
        vector<int> arr(maxValue, 0);

        for (auto a : fruits) {
            arr[a[0]] = a[1];
        }
        for (int i = 1; i < maxValue; i++) {
            arr[i] += arr[i - 1];
        }

        int l = max(0, startPos - k), r = min(maxValue - 1, startPos + k);
        int res = 0;

        for (int i = l; i <= min(r, startPos); i++) {
            int curr_end = min(r, startPos + max(0, (k - 2 * (startPos - i))));
            int lVal = i == 0 ? 0 : arr[i - 1];

            res = max(res, arr[curr_end] - lVal);
        }
        for (int i = r; i >= max(l, startPos); i--) {
            int curr_start =
                max(l, startPos - max(0, (k - 2 * (i - startPos))));
            int lval = curr_start == 0 ? 0 : arr[curr_start - 1];
            res = max(res, arr[i] - lval);
        }

        return res;
    }
};