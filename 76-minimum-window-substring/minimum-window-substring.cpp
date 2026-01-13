class Solution {
public:
    string minWindow(string s, string t) {
        string res = "";
        int len = t.size(), l = 0, r = 0, curr = 0;

        unordered_map<char, int> count;
        for (char c : t) {
            count[c]++;
        }

        while (r < s.size()) {
            if (count.find(s[r]) != count.end()) {
                count[s[r]]--;
                if (count[s[r]] >= 0)
                    curr++;
            }
            if (curr == len) {
                while (l < r) {
                    if (count.find(s[l]) != count.end()) {
                        count[s[l]]++;

                        if (count[s[l]] > 0) {
                            curr--;
                            break;
                        }
                    }
                    l++;
                }
                if (res.size() == 0 || (r - l + 1) < res.size())
                    res = s.substr(l, r - l + 1);

                l++;
            }
            r++;
        }

        return res;
    }
};