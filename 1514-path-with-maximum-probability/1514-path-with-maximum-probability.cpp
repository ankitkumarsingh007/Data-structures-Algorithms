using connType = pair<double, int>;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>> &edges, vector<double> &probs, int start, int target) {
        // support variables
        double costs[n];
        vector<connType> connections[n];
        priority_queue<connType> pq;
        // populating connections
        for (int i = 0, len = edges.size(); i < len; i++) {
            auto &edge = edges[i];
            auto prob = probs[i];
            connections[edge[0]].push_back({prob, edge[1]});
            connections[edge[1]].push_back({prob, edge[0]});
        }
        // preparing costs
        memset(costs, -1, n * sizeof(double));
        costs[start] = 1;
        for (auto &connection: connections[start]) {
            pq.push(connection);
        }
        // trying to reach targer
        while (pq.size()) {
            auto [cost, dest] = pq.top();
            pq.pop();
            // checking if we reached the target
            if (dest == target) return cost;
            // adding new nodes, provided we did not see them before
            if (isnan(costs[dest])) {
                costs[dest] = cost;
                for (auto [nxtCost, nxtDest]: connections[dest]) {
                    pq.push({cost * nxtCost, nxtDest});
                }
            } 
        }
        return 0;
    }
};