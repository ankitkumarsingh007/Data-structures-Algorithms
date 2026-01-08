class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            string curr = "";
            int j = 0, k = 0;
            while (j < res.size() && k < strs[i].size() &&
                   res[j] == strs[i][k]) {
                curr += strs[i][k];
                j++, k++;
            }
            res = curr;
        }

        return res;
    }
};