class Solution {
public:
    unordered_map<string, unordered_map<int, bool>> dp;
    bool find(string& s, int pos, int n) {
        if (pos == (n - 1)) {
            int num = stoi(s);
            if ((num & (num - 1)) == 0)
                return true;
            else
                return false;
        }

        if (dp[s][pos])
            return dp[s][pos];

        for (int i = pos; i < n; i++) {
            if (pos == 0 && s[i] == '0')
                continue;

            swap(s[i], s[pos]);
            bool res = find(s, pos + 1, n);
            swap(s[i], s[pos]);

            if (res)
                return dp[s][pos] = true;
        }

        return dp[s][pos] = false;
    }

    bool reorderedPowerOf2(int n) {
        if ((n & (n - 1)) == 0)
            return true;

        string s = to_string(n);
        int len = s.size();
        return find(s, 0, len);
    }
};