class Solution {
public:
    set<vector<int>> st;
    vector<int> temp;

    void getSubset(vector<int>& nums, int i, int n) {
        if (i == n) {
            st.insert(temp);
            return;
        }

        getSubset(nums, i + 1, n);
        temp.push_back(nums[i]);
        getSubset(nums, i + 1, n);
        temp.pop_back();
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        st.clear(), temp.clear();
        sort(nums.begin(),nums.end());

        int n = nums.size();
        getSubset(nums, 0, n);

        vector<vector<int>> res;
        for (auto a = st.begin(); a != st.end(); a++) {
            res.push_back(*a);
        }

        return res;
    }
};