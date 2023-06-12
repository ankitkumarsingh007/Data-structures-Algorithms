class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int n=nums.size(),j;
        string curr="";
        
        for(int i=0;i<n;i++){
            curr=to_string(nums[i]);
            
            j=i+1;
            while(j<n && nums[j]==nums[j-1]+1)
                j++;
            j--;
            
            if(i==j)
                res.push_back(curr);
            else{
                curr+="->";
                curr+=to_string(nums[j]);
                res.push_back(curr);
                i=j;
            }
        }
        
        return res;
    }
};



