class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> prev, curr, all;

        int n = arr.size();

        for (int i = 0; i < n; i++) {
            if (i != 0) {
                for (auto a : prev) {
                    curr.insert(a | arr[i]);
                    all.insert(a | arr[i]);
                }
            }

            curr.insert(arr[i]);
            all.insert(arr[i]);

            prev = curr;
            curr.clear();
        }

        return all.size();
    }
};