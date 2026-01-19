class Solution {
public:
    int sumVal(int n) {
        int res = 0;
        while (n > 0) {
            int v = n % 10;
            res += (v * v);
            n /= 10;
        }
        return res;
    }

    bool isHappy(int n) {
        unordered_set<int> st;
        while (st.find(n) == st.end() && n != 1) {
            st.insert(n);
            n = sumVal(n);
        }

        return n == 1 ? true : false;
    }
};