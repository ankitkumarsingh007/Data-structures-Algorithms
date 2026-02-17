class Solution {
public:
    int reverseBits(int n) {
        int res = 0, cnt = 32;
        while (cnt--) {
            int a = n & 1;
            n >>= 1;
            res += a;
            if (cnt != 0)
                res <<= 1;
        }

        return res;
    }
};