class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        for (int i = 2; i <= n; i++) {
            int j = i;
            while ((j % 5) == 0) {
                res++;
                j /= 5;
            }
        }

        return res;
    }
};