class Solution {
public:
    typedef long long ll;
    double myPow(double x, int pow) {
        ll n = pow;
        if (n == 0 || x==1)
            return 1;

        if (n < 0) {
            n *= -1;
            x = 1 / x;
        }

        double res = 1, curr = x;
        while (n) {
            if (n & 1)
                res *= x;
            x *= x;
            n >>= 1;
        }

        return res;
    }
};