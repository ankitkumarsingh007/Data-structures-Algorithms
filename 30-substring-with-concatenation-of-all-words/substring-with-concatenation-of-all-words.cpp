class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int len = words[0].size(), n = s.size();
        int totalLen = len * words.size();

        int l = 0, r = 0;
        unordered_map<string, int> freq;
        for (string s : words) {
            freq[s]++;
        }

        for (int pos = 0; pos < min(len, n - totalLen + 1); pos++) {
            l = pos, r = pos;
            unordered_map<string, int> curr;
            while (r <= (n - len) && l <= (n - totalLen)) {
                string s1 = s.substr(r, len);
                if (freq.count(s1) != 0) {
                    curr[s1]++;
                    if (curr[s1] > freq[s1]) {
                        while (curr[s1] != freq[s1]) {
                            string remove = s.substr(l, len);
                            curr[remove]--;
                            l += len;
                        }
                    }
                    r += len;
                    if ((r - l) == totalLen)
                        res.push_back(l);
                } else {
                    curr.clear();
                    l = r + len;
                    r = l;
                }
            }
        }

        return res;
    }
};