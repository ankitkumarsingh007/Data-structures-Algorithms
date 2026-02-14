class Solution {
public:
    unordered_map<string, vector<string>> graph;
    unordered_map<string, unordered_map<string, double>> mp;
    double traverse(string a, string b, double curr, unordered_set<string> &visited) {
        double res = -1;
        visited.insert(a);

        for (string s : graph[a]) {
            if (s == b) {
                return curr * mp[a][s];
            } else if(!(visited.count(s))) {
                res = max(res, traverse(s, b, curr * mp[a][s], visited));
            }
        }
        return res;
    }

    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        int n = values.size();

        for (int i = 0; i < n; i++) {
            string a = equations[i][0], b = equations[i][1];
            graph[a].push_back(b);
            graph[b].push_back(a);
            mp[b][a] = (double(1.0) / values[i]);
            mp[a][b] = values[i];
        }

        vector<double> res;

        for (auto v : queries) {
            if (graph.count(v[0])) {
                unordered_set<string> visited;
                res.push_back(traverse(v[0], v[1], 1, visited));
            } else {
                res.push_back(-1.0);
            }
        }

        return res;
    }
};