class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int dVal = INT_MIN, maxArea = INT_MIN;
        for (auto v : dimensions) {
            int d = pow(v[0], 2) + pow(v[1], 2);

            if (d > dVal) {
                dVal = d;
                maxArea = v[0] * v[1];
            } else if (d == dVal) {
                maxArea = max(maxArea, v[0] * v[1]);
            }
        }

        return maxArea;
    }
};