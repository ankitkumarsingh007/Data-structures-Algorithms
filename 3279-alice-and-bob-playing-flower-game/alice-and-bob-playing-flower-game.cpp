class Solution {
public:
    typedef long long ll;
    long long flowerGame(int n, int m) {
        ll a = min(m, n), b = max(m, n), res = 0;

        res = (a / 2) * b;
        return a % 2 == 1 ? res + b / 2 : res;
    }
};