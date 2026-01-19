class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for (int a : nums)
            st.insert(a);

        int res = 0;

        for (int a : nums) {
            if (st.find(a + 1) == st.end()) {
                int temp = a;
                while (st.find(temp) != st.end()) {
                    st.erase(temp);
                    temp--;
                }
                res = max(res, a - temp);
            }
        }

        return res;
    }
};