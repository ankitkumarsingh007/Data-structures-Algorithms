class Solution {
public:
    int lengthOfLastWord(string s) {
        int res = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] != ' ') {
                while (i >= 0 && s[i] != ' ') {
                    res++;
                    i--;
                }
                return res;
            } else {
                continue;
            }
        }

        return res;
    }
};