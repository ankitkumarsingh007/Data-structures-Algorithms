class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;

        int a = x;
        stack<int> st;

        while (a > 0) {
            st.push(a % 10);
            a /= 10;
        }

        int n = st.size();
        for (int i = 0; i < (n / 2); i++) {
            if ((x % 10) != st.top())
                return false;
            x /= 10;
            st.pop();
        }
        return true;
    }
};