class Solution {
public:
    int minFlips(string s) {
        int c0 = 0, c1 = 0, n = s.size();

        for (char c : s) {
            if (c == '0')
                c0++;
            else
                c1++;
        }

        int res = min(c0, c1);
        if (c1 >= 1)
            res = min(res, c1 - 1);

        if (s[0] == '1' && s[n - 1] == '1' && c1 >= 2)
            res = min(res, c1 - 2);

        return res;
    }
};