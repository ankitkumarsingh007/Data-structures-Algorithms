class Solution {
public:
    void getCombination(vector<int>& arr, int ind, int target,
                        vector<vector<int>>& res, vector<int>& temp) {
        if (target == 0) {
            res.push_back(temp);
            return;
        }
        if (ind == arr.size()) {
            return;
        }

        for (int i = ind; i < arr.size(); i++) {
            if (i != ind && arr[i] == arr[i - 1])
                continue;
            if (arr[i] > target)
                break;

            temp.push_back(arr[i]);
            getCombination(arr, i + 1, target - arr[i], res, temp);
            temp.pop_back();
        }
        return;
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> res;
        vector<int> temp;

        getCombination(candidates, 0, target, res, temp);
        return res;
    };
};