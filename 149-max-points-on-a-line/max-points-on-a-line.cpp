class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int res = 0, n = points.size();
        if (n <= 2)
            return n;
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                int curr = 2;
                for (int k = j + 1; k < n; k++) {
                    if (((points[k][1] - points[i][1]) *
                         (points[j][0] - points[i][0])) ==
                        ((points[j][1] - points[i][1]) *
                         (points[k][0] - points[i][0])))
                        curr++;
                }
                res = max(res, curr);
            }
        }

        return res;
    }
};