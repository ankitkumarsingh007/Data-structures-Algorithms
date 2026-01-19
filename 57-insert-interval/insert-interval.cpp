class Solution {
public:
    vector<vector<int>> mergeInterval(vector<vector<int>>& intervals) {
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

    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        vector<vector<int>> temp;
        int val = newInterval[0];

        for (vector<int> v : intervals) {
            if (val != -1 && val <= v[0]) {
                temp.push_back(newInterval);
                val = -1;
            }
            temp.push_back(v);
        }

        if (val != -1) {
            temp.push_back(newInterval);
        }

        return mergeInterval(temp);
    }
};