class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        string curr = "";

        for (char c : s) {
            if (c == ' ') {
                if (curr.size() > 0)
                    words.push_back(curr);
                curr = "";
            } else {
                curr += c;
            }
        }

        if (curr.size() > 0)
            words.push_back(curr);

        if (words.size() != pattern.size())
            return false;

        unordered_map<string, char> mp;
        vector<bool> taken(26, false);

        for (int i = 0; i < words.size(); i++) {
            string s = words[i];
            char c = pattern[i];
            if (mp.find(s) == mp.end()) {
                if (taken[c - 'a'])
                    return false;
                taken[c - 'a'] = true;
                mp[s] = c;
            } else if (mp[s] != c)
                return false;
        }

        return true;
    }
};