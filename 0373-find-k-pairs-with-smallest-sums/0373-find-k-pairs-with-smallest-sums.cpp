class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        int m=nums2.size();
        vector<vector<int>>ans;
        priority_queue<pair<int,pair<int,int>>>pq;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int sum=nums1[i]+nums2[j];
                if(pq.size()<k){
                pq.push({sum,{nums1[i],nums2[j]}});
            }else{
                if(pq.top().first > sum){
                    pq.pop();
                    pq.push({sum,{nums1[i],nums2[j]}});
                }else{
                    break;
                }
            }
            }
        }
        while(pq.size()>0){
            vector<int>temp;
            temp.push_back(pq.top().second.first);
            temp.push_back(pq.top().second.second);
            ans.push_back(temp);
            pq.pop();
        }
return ans;
    }
};