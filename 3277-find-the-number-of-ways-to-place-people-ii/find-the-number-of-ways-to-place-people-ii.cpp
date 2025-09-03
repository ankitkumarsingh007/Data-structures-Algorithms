bool comp(vector<int> v1, vector<int> v2) {
    if (v1[0] == v2[0]) {
        return v1[1] > v2[1];
    }
    return v1[0] < v2[0];
}

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), comp);
        int n = points.size(), res = 0;

        for (int i = 0; i < (n - 1); i++) {
            for (int j = i + 1, y = INT_MIN; j < n; j++) {
                if (points[j][1] <= points[i][1] && y < points[j][1]) {
                    res++;
                    y = points[j][1];
                }
            }
        }

        return res;
    }
};