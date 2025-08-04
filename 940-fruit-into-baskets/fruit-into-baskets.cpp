class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int first = -1, second = -1;
        int start = 0, res = 0, n = fruits.size();

        for (int i = 0; i < n; i++) {
            if (first == -1) {
                first = i;
            } else if (fruits[first] == fruits[i]) {
                first = i;
            } else if (second == -1) {
                second = i;
            } else if (fruits[second] == fruits[i]) {
                second = i;
            } else {
                if (first < second) {
                    start = first + 1;
                    first = i;
                } else {
                    start = second + 1;
                    second = i;
                }
            }

            res = max(res, i - start + 1);
        }

        return res;
    }
};