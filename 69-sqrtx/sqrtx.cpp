class Solution {
public:
    typedef long long ll;
    int mySqrt(int x) {
        for (ll i = 0; i <= x; i++) {
            ll j = (i * i);
            if (j == x)
                return i;
            else if (j > x)
                return i - 1;
        }
        return 0;
    }
};