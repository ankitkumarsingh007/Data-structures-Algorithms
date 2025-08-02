class Solution {
public:
    typedef long long ll;
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        map<ll, ll> mp1, mp2;

        for (ll a : basket1) {
            mp1[a]++;
        }
        for (ll a : basket2) {
            mp2[a]++;
        }

        auto it1 = mp1.begin(), it2 = mp2.begin();
        ll minval = INT_MAX;
        vector<ll> transfer;

        while (it1 != mp1.end() && it2 != mp2.end()) {
            ll num1 = it1->first, num2 = it2->first, freq1 = it1->second,
                freq2 = it2->second;
            minval = min(minval, min(num1, num2));

            if (num1 == num2) {
                if (abs(freq1 - freq2) % 2 == 0) {
                    ll cnt = abs(freq1 - freq2) / 2;
                    while (cnt--) {
                        transfer.push_back(num1);
                    }
                } else {
                    return -1;
                }
                it1++, it2++;
            } else if (num1 < num2) {
                if (freq1 % 2 == 0) {
                    ll cnt = freq1 / 2;
                    while (cnt--) {
                        transfer.push_back(num1);
                    }
                } else {
                    return -1;
                }
                it1++;
            } else {
                if (freq2 % 2 == 0) {
                    ll cnt = freq2 / 2;
                    while (cnt--) {
                        transfer.push_back(num2);
                    }
                } else {
                    return -1;
                }
                it2++;
            }
        }
        while (it1 != mp1.end()) {
            ll num1 = it1->first, freq1 = it1->second;
            minval = min(minval, num1);

            if (freq1 % 2 == 0) {
                ll cnt = freq1 / 2;
                while (cnt--) {
                    transfer.push_back(num1);
                }
            } else {
                return -1;
            }
            it1++;
        }
        while (it2 != mp2.end()) {
            ll num2 = it2->first, freq2 = it2->second;
            minval = min(minval, num2);

            if (freq2 % 2 == 0) {
                ll cnt = freq2 / 2;
                while (cnt--) {
                    transfer.push_back(num2);
                }
            } else {
                return -1;
            }
            it2++;
        }

        ll totalMove = transfer.size() / 2;
        ll res = 0;
        for (ll i = 0; i < totalMove; i++) {
            cout << transfer[i] << endl;
            res += min(minval * 2, transfer[i]);
        }

        return res;
    }
};