class Solution {
public:
    int minGenerations(vector<vector<int>>& points, vector<int>& target) {
        set<vector<int>> st;
        int res = 0;

        for (auto v : points)
            st.insert(v);

        if (st.count(target))
            return 0;

        if (st.size() == 1)
            return -1;

        while (true) {
            int n = points.size();
            vector<vector<int>> t;
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    vector<int> v1 = points[i], v2 = points[j];
                    if (v1 == v2)
                        continue;

                    vector<int> v = {(v1[0] + v2[0]) / 2, (v1[1] + v2[1]) / 2,
                                     (v1[2] + v2[2]) / 2};
                    if (v == target)
                        return res + 1;
                    if (!st.count(v)) {
                        st.insert(v);
                        t.push_back(v);
                    }
                }
            }

            if (t.size() == 0)
                return -1;
            for (auto v : t) {
                points.push_back(v);
            }
            res++;
        }

        return res;
    }
};