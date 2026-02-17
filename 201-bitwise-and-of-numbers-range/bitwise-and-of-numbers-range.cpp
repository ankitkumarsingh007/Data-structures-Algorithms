class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int i = 0, curr = right;
        while (curr) {
            curr >>= 1;
            i++;
        }

        int res = 0;
        for (int a = i - 1; a >= 0; a--) {
            if (((1 << a) & left) == ((1 << a) & right))
                res ^= ((1 << a) & left);
            else
                break;
        }

        return res;
    }
};