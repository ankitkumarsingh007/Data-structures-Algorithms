class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int len = words[0].size(), n = s.size();
        int totalLen = words.size() * len;

        unordered_map<string, int> freq, curr;

        for (string s : words)
            freq[s]++;

        for (int i = 0; i < len; i++) {
            int l = i, r = i;
            curr.clear();
            while (l <= (n - totalLen) && r <= (n - len)) {
                string s1 = s.substr(r, len);
                curr[s1]++;
                if (freq[s1] != 0) {
                    while (curr[s1] > freq[s1]) {
                        string s2 = s.substr(l, len);
                        l += len;
                        curr[s2]--;
                    }
                    r += len;
                } else {
                    l = r + len;
                    r = l;
                    curr.clear();
                }
                if ((r - l) == totalLen)
                    res.push_back(l);
            }
        }

        return res;
    }
};