class Solution {
public:
    double findMedian(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int l1 = 0,r1 = n1 - 1;

        int firstEnd,firstStart,secondEnd,secondStart;

        while(true){
            int mid1 = (l1+r1+1)/2;
            int mid2 = (n1+n2)/2 - mid1;
            firstEnd = (mid1 == 0) ? INT_MIN : nums1[mid1-1] ;
            firstStart = (mid1 == n1) ? INT_MAX : nums1[mid1];
            secondEnd = (mid2==0) ? INT_MIN : nums2[mid2-1];
            secondStart = (mid2 == n2) ? INT_MAX : nums2[mid2];

            if(firstEnd <= secondStart && secondEnd <= firstStart){
                if(((n1+n2)%2)==0){
                    return (max(firstEnd,secondEnd) + min(firstStart,secondStart))/2.0;
                }else{
                    return min(firstStart,secondStart);
                }
            }else if(firstEnd>secondStart){
                r1 = mid1-1;
            }else{
                l1 = mid1 + 1;
            }
        }

        return 0.0;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() <= nums2.size())
            return findMedian(nums1, nums2);
        else
            return findMedian(nums2, nums1);
    }
};