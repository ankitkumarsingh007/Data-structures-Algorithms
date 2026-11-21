class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();

        deque<int> dq;
        vector<int> res;

        for (int i = 0; i < k; i++) {
            if (dq.empty() || nums[dq.back()] > nums[i])
                dq.push_back(i);
            else {
                while (!dq.empty() && nums[dq.back()] <= nums[i])
                    dq.pop_back();
                dq.push_back(i);
            }
        }

        res.push_back(nums[dq.front()]);

        for (int i = k; i < n; i++) {
            if (dq.front() == (i - k))
                dq.pop_front();

            if (dq.empty() || nums[dq.back()] > nums[i])
                dq.push_back(i);
            else {
                while (!dq.empty() && nums[dq.back()] <= nums[i])
                    dq.pop_back();
                dq.push_back(i);
            }
            res.push_back(nums[dq.front()]);
        }

        return res;
    }
};