class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size(), res = 0;
        vector<bool> used(n, false);

        for (int i = 0; i < n; i++) {
            int j = 0;
            for (j; j < n; j++) {
                if (!used[j] && baskets[j] >= fruits[i]) {
                    used[j] = true;
                    break;
                }
            }
            if (j == n) {
                res++;
            }
        }

        return res;
    }
};