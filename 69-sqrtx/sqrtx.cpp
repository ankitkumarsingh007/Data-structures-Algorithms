class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1)
            return x;

        int l = 1, r = x, res = l;

        while (l <= r) {
            int m = l + (r - l) / 2;

            if (m <= (x / m)) {
                l = m + 1;
                res = m;
            } else {
                r = m - 1;
            }
        }

        return res;
    }
};