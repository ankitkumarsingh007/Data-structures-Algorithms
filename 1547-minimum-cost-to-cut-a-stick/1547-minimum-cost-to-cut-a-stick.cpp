class Solution {
public:
    vector<int> arr;
    vector<vector<int>> dp;
    
    int helper(int l,int r,int i,int j){
        if(i>j)
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int res=INT_MAX;
        for(int k=i;k<=j;k++){
            res=min(res,r-l+helper(l,arr[k],i,k-1)+helper(arr[k],r,k+1,j));
        }
        return dp[i][j]=res;
    }
    
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        arr=cuts;
        
        dp.resize(arr.size(),vector<int>(arr.size(),-1));
        
        return helper(0,n,0,arr.size()-1);
    }
};