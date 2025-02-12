class Solution {
public:
    set<vector<int>> st;
    vector<int> temp;
    int sum;
    int total;

    void getCombination(vector<int>& arr, int i, int n) {
        if (sum > total || i == n) {
            return;
        }
        if (sum == total) {
            st.insert(temp);
            return;
        }

        getCombination(arr, i + 1, n);
        sum += arr[i];
        temp.push_back(arr[i]);
        getCombination(arr, i, n);
        sum -= arr[i];
        temp.pop_back();
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        st.clear(), temp.clear(), sum = 0, total = target;
        sort(candidates.begin(), candidates.end());

        getCombination(candidates, 0, candidates.size());

        vector<vector<int>> res;
        for (auto a = st.begin(); a != st.end(); a++) {
            res.push_back(*a);
        }

        return res;
    }
};