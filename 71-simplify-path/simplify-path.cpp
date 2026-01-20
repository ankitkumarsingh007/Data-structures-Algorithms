class Solution {
public:
    string simplifyPath(string s) {
        int n = s.size();
        string res = "/", curr = "";
        stack<string> st;

        for (int i = 0; i < n;) {
            if (s[i] == '/') {
                if (curr == "..") {
                    if (!st.empty())
                        st.pop();
                } else if (curr != "." && curr.size() > 0) {
                    st.push(curr);
                }
                curr = "";

                while (i < n && s[i] == '/')
                    i++;
            } else {
                while (i < n && s[i] != '/')
                    curr += s[i++];
            }
        }

        if (curr == "..") {
            if (!st.empty())
                st.pop();
        } else if (curr != "." && curr.size() > 0) {
            st.push(curr);
        }

        vector<string> temp;
        while (!st.empty()) {
            temp.push_back(st.top());
            st.pop();
        }

        for (int i = (temp.size() - 1); i >= 0; i--) {
            if (i != (temp.size() - 1))
                res += '/';

            res += temp[i];
        }

        return res;
    }
};