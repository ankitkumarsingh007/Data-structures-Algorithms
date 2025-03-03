class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> arr;
        vector<int> fact(n + 1, 1);

        for (int i = 1; i <= n; i++) {
            arr.push_back(i);
            fact[i] = i * fact[i - 1];
        }

        k--;
        string res = "";

        while (n--) {
            int a = fact[n];

            int num = k / a;
            k %= a;
            res += char('0' + arr[num]);

            arr.erase(arr.begin()+num);
        }

        return res;
    }
};