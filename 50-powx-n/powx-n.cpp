class Solution {
public:
    typedef long long ll;
    double myPow(double x, int n) {
        if (n == 0)
            return 1;
        if (x == 0)
            return x;

        double res = 1;
        // Saving from corner case when n==INT_MIN 
        ll power = abs(ll(n));

        if (n < 0) {
            x = 1 / x;
        }

        while (power != 0) {
            if (power & 1)
                res *= x;

            x *= x;
            power>>=1;
        }

        return res;
    }
};