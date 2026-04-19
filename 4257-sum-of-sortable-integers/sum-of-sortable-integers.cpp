typedef pair<int, int> pp;
class Solution {
public:
    pp isSortedRotated(vector<int>& nums, int l, int r) {
        int mxPos =
            max_element(nums.begin() + l, nums.begin() + r + 1) - nums.begin();
        int mnPos =
            min_element(nums.begin() + l, nums.begin() + r + 1) - nums.begin();
        
        // this is needed, as array can have repeating values also. So make sure that max & min should be consecutive
        for(int i=l;i<r;i++){
            if(nums[i]==nums[mxPos] && nums[i+1]==nums[mnPos]){
                mnPos = i+1, mxPos = i;
                break;
            }
        }

        if (is_sorted(nums.begin() + l, nums.begin() + r + 1)) {
            return {nums[mnPos], nums[mxPos]};
        }
        if ((mnPos - mxPos) == 1 && nums[l] >= nums[r]) {
            if (is_sorted(nums.begin() + l, nums.begin() + mnPos) &&
                is_sorted(nums.begin() + mnPos, nums.begin() + r + 1))
                return {nums[mnPos], nums[mxPos]};
        }
        return {-1, -1};
    }
    int sortableIntegers(vector<int>& nums) {
        vector<int> arr;
        int n = nums.size();

        for (int i = 1; i <= n; i++) {
            if ((n % i) == 0)
                arr.push_back(i);
        }

        int res = 0;
        for (int k : arr) {
            int l = 0;
            pp prev = {};
            for (l = 0; l < n; l += k) {
                pp curr = isSortedRotated(nums, l, l + k - 1);
                if (curr.first == -1)
                    break;
                if (prev.first && prev.second > curr.first)
                    break;
                prev  = curr;
            }

            if (l >= n)
                res+=k;
        }
        return res;
    }
};