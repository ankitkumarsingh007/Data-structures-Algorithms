class Solution {
public:
    char openChar(char c) {
        if (c == '(' || c == ')')
            return '(';
        if (c == '{' || c == '}')
            return '{';
        if (c == '[' || c == ']')
            return '[';

        return c;
    }

    bool isValid(string s) {
        stack<char> st;

        for (char c : s) {
            char c1 = openChar(c);
            if (c1 == c) {
                st.push(c);
                continue;
            }
            if (!st.empty() && st.top() == c1) {
                st.pop();
                continue;
            }
            return false;
        }

        return st.size() == 0;
    }
};