class Solution {
public:
    typedef long long ll;
    double myPow(double x, ll n) {
        if (n == 0) {
            return 1.0;
        }
        if (n < 0) {
            x = 1.0 / x;
            n = -n;
        }

        double val = myPow(x, n / 2);

        return n % 2 == 1 ? val * val * x : val * val;
    }
};