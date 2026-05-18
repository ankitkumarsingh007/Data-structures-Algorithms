class Solution {
public:
    typedef pair<int, int> pp;

    static bool comp(pp& a, pp& b) {
        if (a.first == b.first)
            return a.second < b.second;
        else
            return a.first < b.first;
    }

    int maxFixedPoints(vector<int>& nums) {
        vector<pp> arr;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= i) {
                arr.push_back({i - nums[i], nums[i]});
            }
        }

        sort(arr.begin(), arr.end(), comp);

        vector<int> res;
        for (auto pp : arr) {
            auto it = lower_bound(res.begin(), res.end(), pp.second);
            if (it == res.end()) {
                res.push_back(pp.second);
            } else {
                *it = pp.second;
            }
        }

        return res.size();
    }
};