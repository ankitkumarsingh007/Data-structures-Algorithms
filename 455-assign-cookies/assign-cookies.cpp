class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int n = g.size(), m = s.size(), res = 0, j = 0;

        for (int i = 0; i < n; i++) {
            for (j; j < m; j++) {
                if (s[j] >= g[i]) {
                    res++;
                    j++;
                    break;
                }
            }
            if (j == m)
                break;
        }

        return res;
    }
};