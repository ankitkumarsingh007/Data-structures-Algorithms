class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }

        vector<vector<char>> arr(numRows);
        int ind = 0;
        bool straight = true;
        for (char c : s) {
            if (ind == 0) {
                straight = true;
            } else if (ind == (numRows - 1)) {
                straight = false;
            }
            arr[ind].push_back(c);
            ind = straight ? ind + 1 : ind - 1;
        }

        string res = "";
        for (auto v : arr) {
            for (char c : v) {
                res += c;
            }
        }

        return res;
    }
};