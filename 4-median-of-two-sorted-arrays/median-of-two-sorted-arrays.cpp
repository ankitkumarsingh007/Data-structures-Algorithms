class Solution {
public:
    double findMid(vector<int>& nums1, vector<int>& nums2, int pos) {
        int m = nums1.size(), n = nums2.size();

        if (m == 0) {
            return nums2[pos];
        } else if (n == 0) {
            return nums1[pos];
        }

        int l = min(nums1[0], nums2[0]), r = max(nums1[m - 1], nums2[n - 1]);

        while (l < r) {
            int mid = l + (r - l) / 2;

            int cnt =
                (upper_bound(nums1.begin(), nums1.end(), mid) - nums1.begin()) +
                (upper_bound(nums2.begin(), nums2.end(), mid) - nums2.begin());

            if(cnt<=pos){
                l=mid+1;
            }else{
                r=mid;
            }
        }

        return l;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size(), total = n + m;

        if (total % 2 == 1) {
            return findMid(nums1, nums2, total / 2);
        } else {
            return (findMid(nums1, nums2, total / 2 - 1) +
                    findMid(nums1, nums2, total / 2)) /
                   2.0;
        }
    }
};