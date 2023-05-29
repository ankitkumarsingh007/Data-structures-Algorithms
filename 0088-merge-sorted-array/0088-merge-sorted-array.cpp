class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        reverse(nums1.begin(),nums1.begin()+m);
        reverse(nums1.begin(),nums1.end());
        
        int i=n,j=0,k=0;
        while(i<(m+n) && j<n){
            if(nums1[i]<=nums2[j])
                nums1[k++]=nums1[i++];
            else
                nums1[k++]=nums2[j++];
        }
        while(i<(m+n)){
            nums1[k++]=nums1[i++];
        }
        while(j<n){
            nums1[k++]=nums2[j++];
        }
        
        return;
    }
};