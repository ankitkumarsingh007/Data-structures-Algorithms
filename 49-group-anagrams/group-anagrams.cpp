class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> mp;
        for (string s : strs) {
            string curr = s;
            sort(curr.begin(), curr.end());
            mp[curr].push_back(s);
        }

        for (auto itr : mp) {
            vector<string> v = itr.second;
            res.push_back(v);
        }

        return res;
    }
};