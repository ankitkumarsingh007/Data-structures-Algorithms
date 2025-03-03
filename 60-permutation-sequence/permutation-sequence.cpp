class Solution {
public:
    vector<int> deleteElement(vector<int> arr, int ind) {
        vector<int> temp;
        for (int i = 0; i < arr.size(); i++) {
            if (i != ind)
                temp.push_back(arr[i]);
        }

        return temp;
    }

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

            arr = deleteElement(arr, num);
        }

        return res;
    }
};