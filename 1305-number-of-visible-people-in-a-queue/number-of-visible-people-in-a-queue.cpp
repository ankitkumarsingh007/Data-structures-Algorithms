class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        vector<int> res;
        stack<int> st;

        int n = heights.size();
        for (int i = n - 1; i >= 0; i--) {
            int cnt = 0;
            while (!st.empty() && heights[i] > heights[st.top()]) {
                st.pop();
                cnt++;
            }

            if (st.empty()) {
                res.push_back(cnt);
            } else {
                res.push_back(cnt + 1);
            }

            st.push(i);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};