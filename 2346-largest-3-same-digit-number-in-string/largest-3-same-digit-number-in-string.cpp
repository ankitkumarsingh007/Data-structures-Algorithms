class Solution {
public:
    string largestGoodInteger(string s) {
        int n = s.size();
        string res = "";

        for (int i = 0; i < n - 2; i++) {
            if (s[i] == s[i + 1]) {
                if (s[i] == s[i + 2]) {
                    if (res == "") {
                        res = s.substr(i, 3);
                    } else if (res[0] < s[i]) {
                        res = s.substr(i, 3);
                    }
                    i += 2;
                } else {
                    i++;
                }
            }
        }

        return res;
    }
};