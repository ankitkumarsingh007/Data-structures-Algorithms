bool comp(vector<int>& a, vector<int>& b) {
    if (a[0] == b[0]) {
        return a[1] < b[1];
    }
    return a[0] < b[0];
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);

        vector<vector<int>> res;
        int start = intervals[0][0], end = intervals[0][1],
            n = intervals.size();

        for (int i = 1; i < n; i++) {
            if (end >= intervals[i][0]) {
                end = max(end, intervals[i][1]);
            } else {
                res.push_back({start, end});
                start = intervals[i][0], end = intervals[i][1];
            }
        }
        res.push_back({start, end});

        return res;
    }
};