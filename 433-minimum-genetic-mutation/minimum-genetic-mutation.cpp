class Solution {
public:
    bool isMutable(string a, string b) {
        int cnt = 0;
        for (int i = 0; i < 8; i++) {
            if (a[i] != b[i])
                cnt++;
        }
        return cnt == 1;
    }

    int minMutation(string startGene, string endGene, vector<string>& bank) {
        bank.push_back(startGene);
        unordered_map<string, vector<string>> graph;

        for (int i = 0; i < bank.size(); i++) {
            for (int j = i + 1; j < bank.size(); j++) {
                string a = bank[i], b = bank[j];
                if (isMutable(a, b)) {
                    graph[a].push_back(b);
                    graph[b].push_back(a);
                }
            }
        }

        queue<pair<string, int>> q;
        q.push({startGene, 0});
        unordered_set<string> visited;
        visited.insert(startGene);

        while (!q.empty()) {
            pair<string, int> pp = q.front();
            q.pop();

            string s = pp.first;
            int dis = pp.second;

            if (s == endGene)
                return dis;

            for (string s1 : graph[s]) {
                if (!visited.count(s1)) {
                    visited.insert(s1);
                    q.push({s1, dis + 1});
                }
            }
        }

        return -1;
    }
};