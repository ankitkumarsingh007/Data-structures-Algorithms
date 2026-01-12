class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) {
            return 0;
        }

        int curr_head = -1, res = INT_MIN;

        vector<int> charPos(256, -1);
        for (int i = 0; i < s.size(); i++) {
            curr_head = max(curr_head, charPos[s[i]]);
            charPos[s[i]] = i;

            res = max(res, i - curr_head);
        }

        return res;
    }
};