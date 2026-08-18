class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b) { return a[1] < b[1]; }

    int lastValid(vector<vector<int>>& arr, int i) {
        int l = 0, r = i - 1;
        int res = -1;
        while (l <= r) {
            int m = l + (r - l) / 2;

            if (arr[m][1] > arr[i][0]) {
                r = m - 1;
            } else {
                res = m;
                l = m + 1;
            }
        }
        return res;
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime,
                      vector<int>& profit) {
        vector<vector<int>> arr;

        for (int i = 0; i < profit.size(); i++) {
            arr.push_back({startTime[i], endTime[i], profit[i]});
        }

        sort(arr.begin(), arr.end(), comp);

        int n = profit.size();

        vector<int> dp(n, -1);

        dp[0] = arr[0][2];

        for (int i = 1; i < n; i++) {
            int profit = arr[i][2], pos = lastValid(arr, i);
            if (pos != -1)
                profit += dp[pos];

            dp[i] = max(dp[i - 1], profit);
        }

        return dp[n - 1];
    }
};