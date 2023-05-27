class Solution {
public:
    vector<int> dp;
    int helper(vector<int> &arr,int pos){
        int n=arr.size();
        if(pos>=n)
            return 0;
        
        if(dp[pos]!=-1)
            return dp[pos];
        
        int res=INT_MIN,limit=min(pos+3,n),curr=0;
        
        for(int i=pos;i<limit;i++){
            curr+=arr[i];
            
            int a=INT_MAX;
            for(int j=1;j<=3;j++){
                a=min(a,helper(arr,i+j+1));
            }
            res=max(res,curr+a);
        }
        
        return dp[pos]=res;
    }
    
    string stoneGameIII(vector<int>& arr) {
        dp.resize(arr.size(),-1);
        
        int res=helper(arr,0);
        
        int total=0;
        for(int a:arr)
            total+=a;
        
        total-=res;
        
        if(total>res)
            return "Bob";
        else if(total==res)
            return "Tie";
        else
            return "Alice";
    }
};