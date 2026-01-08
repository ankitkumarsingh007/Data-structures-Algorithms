class Solution {
public:
    string getString(string c, int cnt) {
        string s = "";
        while (cnt--) {
            s += c;
        }
        return s;
    }

    string intToRoman(int num) {
        string res = "";
        vector<string> c = {"I",  "IV", "V",  "IX", "X",  "XL", "L",
                            "XC", "C",  "CD", "D",  "CM", "M"};
        vector<int> val = {1,  4,   5,   9,   10,  40,  50,
                           90, 100, 400, 500, 900, 1000};

        for (int i = val.size() - 1; i >= 0; i--) {
            if (num >= val[i]) {
                res += getString(c[i], num / val[i]);
                num %= val[i];
            }
        }

        return res;
    }
};