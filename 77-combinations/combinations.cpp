class Solution {
public:
    void dfs(vector<vector<int>>& res, vector<int>& v, int n, int k, int i) {
        if (i == (n + 1)) {
            if (v.size() == k)
                res.push_back(v);
            return;
        }

        v.push_back(i);
        dfs(res, v, n, k, i + 1);
        v.pop_back();
        dfs(res, v, n, k, i + 1);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> v;
        dfs(res, v, n, k, 1);
        return res;
    }
};