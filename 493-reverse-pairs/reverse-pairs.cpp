class Solution {
public:
    typedef long long ll;
    int pairs;
    Solution() { pairs = 0; }

    void calculatePairs(vector<int>& arr, int l, int r) {
        if (r == l) {
            return;
        }

        int size = r - l + 1, mid = l + size / 2, i = l, j = mid;
        calculatePairs(arr, l, mid - 1);
        calculatePairs(arr, mid, r);

        while (i < mid && j <= r) {
            if ((arr[j] * ll(2)) < arr[i]) {
                pairs += (mid - i);
                j++;
            } else {
                i++;
            }
        }

        vector<int> temp;
        i = l, j = mid;
        while (i < mid && j <= r) {
            if (arr[j] < arr[i]) {
                temp.push_back(arr[j++]);
            } else {
                temp.push_back(arr[i++]);
            }
        }

        while (i < mid)
            temp.push_back(arr[i++]);

        while (j <= r)
            temp.push_back(arr[j++]);

        for (int i = l; i <= r; i++) {
            arr[i] = temp[i - l];
        }

        return;
    }

    int reversePairs(vector<int>& nums) {
        Solution();
        calculatePairs(nums, 0, nums.size() - 1);

        return pairs;
    }
};