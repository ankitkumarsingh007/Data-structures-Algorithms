class Solution {
public:
    int subarraysDivByK(vector<int>& arr, int k) {
        int n=arr.size();
	    int sum=0,ans=0;
	    unordered_map<int,int> mp;
        mp[0]=1;
	    
	    for(int i=0;i<n;i++){
	        sum+=arr[i];
	        
	        sum%=k;
	        
	        //why that's required even if all constraints are in limit
	        //bcz negative values are present too
	        if(sum<0)
	        sum+=k;
	        
	        if(mp.find(sum)!=mp.end())
	        ans+=mp[sum];
            
	        mp[sum]++;
	    }
	    
	    return ans;
    }
};