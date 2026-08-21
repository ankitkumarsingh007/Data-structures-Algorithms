// Just take care of data overflow while doing sum
class Solution {
public:
    typedef long long ll;
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        ll n = nums.size();

        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        for (ll i = 0; i < (n - 3);) {
            for (ll j = i + 1; j < (n - 2);) {
                ll k = j + 1, l = n - 1;

                while (k < l) {
                    ll sum = ll(nums[i]) + nums[j] + nums[k] + nums[l];

                    if (sum == target) {
                        res.push_back({nums[i], nums[j], nums[k], nums[l]});
                        do {
                            k++;
                        } while (k < l && nums[k] == nums[k - 1]);
                        do {
                            l--;
                        } while (k < l && nums[l] == nums[l + 1]);
                    } else if (sum < target) {
                        k++;
                    } else {
                        l--;
                    }
                }
                do {
                    j++;
                } while (j < (n - 2) && nums[j] == nums[j - 1]);
            }
            do {
                i++;
            } while (i < (n - 3) && nums[i] == nums[i - 1]);
        }

        return res;
    }
};