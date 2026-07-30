class Solution {
public:
    typedef pair<int, int> pp;

    int checkConnected(string s1, string s2) {
        int n = s1.size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (s1[i] != s2[i])
                cnt++;
            if (cnt > 1)
                return false;
        }
        return cnt == 1;
    }

    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        unordered_set<string> st;
        for (string s : wordList) {
            st.insert(s);
        }
        if (st.find(endWord) == st.end()) {
            cout << "not found" << endl;
            return 0;
        }

        st.erase(beginWord);
        st.erase(endWord);

        vector<string> words;
        words.push_back(beginWord);
        for (auto s : st) {
            words.push_back(s);
        }
        words.push_back(endWord);

        int n = words.size();
        vector<vector<int>> graph(n);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (checkConnected(words[i], words[j])) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }

        queue<pp> q;
        vector<bool> visited(n, false);

        q.push({0, 1});

        while (!q.empty()) {
            pp p = q.front();
            q.pop();

            for (int i : graph[p.first]) {
                if (!visited[i]) {
                    if (i == (n - 1))
                        return p.second + 1;
                    q.push({i, p.second + 1});
                    visited[i] = true;
                }
            }
        }

        return 0;
    }
};