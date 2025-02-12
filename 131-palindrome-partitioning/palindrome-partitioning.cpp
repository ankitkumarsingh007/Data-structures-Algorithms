class Solution {
public:
    vector<vector<string>> res;

    bool isPalindrome(string s) {
        int n = s.size();
        if (n == 0)
            return false;
        if (n == 1)
            return true;

        int l = 0, r = n - 1;
        while (l < r) {
            if (s[l] != s[r])
                return false;
            l++,r--;
        }

        return true;
    }

    void getPartition(string s, int i, string curr, vector<string>& temp) {
        if (i == s.size()) {
            if (isPalindrome(curr)) {
                temp.push_back(curr);
                res.push_back(temp);
                temp.pop_back();
            }

            return;
        }

        if (isPalindrome(curr)) {
            temp.push_back(curr);
            getPartition(s, i + 1, {s[i]}, temp);
            temp.pop_back();
        }

        curr += s[i];
        getPartition(s, i + 1, curr, temp);
    }

    vector<vector<string>> partition(string s) {
        vector<string> temp;

        getPartition(s, 0, "", temp);

        return res;
    }
};