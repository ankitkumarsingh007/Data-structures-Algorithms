bool comp(vector<int>& a, vector<int>& b) { return a[1] < b[1]; }

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int res = 1;
        sort(points.begin(), points.end(), comp);

        int end = points[0][1], n = points.size();
        for (int i = 1; i < n; i++) {
            if (end >= points[i][0]) {
                continue;
            } else {
                res++;
                end = points[i][1];
            }
        }

        return res;
    }
};