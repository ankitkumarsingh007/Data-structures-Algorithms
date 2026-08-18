class Solution {
public:
    string convert(string s, int numRows) {
        string res = "";
        int n = s.size();

        if (n <= numRows || numRows==1)
            return s;

        int delta = 2 * (numRows - 1);
        int currDelta = delta;

        for (int row = 0; row < numRows; row++) {
            if (row == 0 || row == (numRows - 1)) {
                int i = row;
                while (i < n) {
                    res += s[i];
                    i += delta;
                }
            } else {
                int i = row;
                currDelta -= 2;
                while (i < n) {
                    res += s[i];
                    i += currDelta;

                    if (i < n) {
                        res += s[i];
                        i += (delta - currDelta);
                    }
                }
            }
        }

        return res;
    }
};