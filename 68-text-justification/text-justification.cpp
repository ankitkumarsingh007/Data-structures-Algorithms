class Solution {
public:
    string joinStringArray(vector<string>& v) {
        string res = "";
        for (string s : v) {
            res += s;
        }
        return res;
    }
    string addSpace(int cnt) {
        string res = "";
        while (cnt--) {
            res += ' ';
        }
        return res;
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res, curr;
        int currSize = 0;

        for (int i = 0; i < words.size(); i++) {
            string s = words[i];

            if ((currSize + curr.size() + s.size()) > maxWidth) {
                int extra_space = maxWidth - currSize;
                int space = extra_space / max(1, int(curr.size() - 1));
                int remainder = extra_space % max(1, int(curr.size() - 1));

                for (int j = 0; j < max(1, int(curr.size() - 1)); j++) {
                    curr[j] += addSpace(space);
                    if (remainder) {
                        curr[j] += " ";
                        remainder--;
                    }
                }
                res.push_back(joinStringArray(curr));
                curr.clear();
                currSize = 0;
            }

            curr.push_back(s);
            currSize += s.size();
        }

        for (int i = 0; i < (curr.size() - 1); i++) {
            curr[i] += " ";
        }
        curr[curr.size() - 1] +=
            addSpace(maxWidth - (currSize + curr.size() - 1));
        res.push_back(joinStringArray(curr));

        return res;
    }
};