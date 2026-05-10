class Solution {
public:
    vector<int> kthRemainingInteger(vector<int>& nums,
                                    vector<vector<int>>& queries) {

        vector<int> res;
        int n = nums.size();

        // prefix[i] = count of even numbers in nums[0...i-1]
        // Used to quickly find how many even numbers exist in any range
        vector<int> prefix(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            prefix[i] = prefix[i - 1] + (nums[i - 1] % 2 == 0);
        }

        for (auto& v : queries) {

            int l = v[0];
            int r = v[1];
            int k = v[2];

            // Count of even numbers strictly before nums[l]
            // Example:
            // nums[l] = 10
            // evens before it -> 2,4,6,8 => 4 numbers
            int l_cnt = (nums[l] - 1) / 2;

            // Total even numbers up to nums[r]
            int r_cnt = nums[r] / 2;

            // Number of even elements removed from nums[l...r]
            int rem = prefix[r + 1] - prefix[l];

            /*
                CASE 1:
                kth remaining even number lies BEFORE nums[l]

                Since no removed numbers affect this region,
                answer is simply kth even number = 2*k
            */
            if (l_cnt >= k) {
                res.push_back(2 * k);
            }

            /*
                CASE 2:
                kth remaining even number lies AFTER nums[r]

                Remaining even numbers up to nums[r] are:
                    total_even_till_r - removed_even_count

                If this count is still < k,
                then answer must be after nums[r]

                Since 'rem' even numbers are deleted,
                answer gets shifted by rem positions
            */
            else if ((r_cnt - rem) < k) {
                res.push_back(2 * (k + rem));
            }

            /*
                CASE 3:
                kth remaining even number lies INSIDE range
                [nums[l], nums[r]]

                Use Binary Search to find first index where
                remaining even count becomes >= k
            */
            else {

                int s = l;
                int e = r;

                while (s <= e) {

                    int m = s + (e - s) / 2;

                    // Total even numbers up to nums[m]
                    int total_even = nums[m] / 2;

                    // Removed even numbers from nums[l...m]
                    int removed = prefix[m + 1] - prefix[l];

                    // Remaining even numbers till nums[m]
                    int remaining = total_even - removed;

                    /*
                        If remaining count is still smaller than k,
                        answer lies further right
                    */
                    if (remaining < k) {
                        s = m + 1;
                    }

                    /*
                        Otherwise current index may already contain
                        kth remaining number, try moving left
                    */
                    else {
                        e = m - 1;
                    }
                }

                /*
                    s is now the first position where
                    remaining count >= k

                    Count how many removed evens exist before s
                */
                rem = prefix[s] - prefix[l];

                /*
                    Every removed even shifts answer forward by 1

                    Hence answer = 2 * (k + removed_before_s)
                */
                res.push_back(2 * (k + rem));
            }
        }

        return res;
    }
};