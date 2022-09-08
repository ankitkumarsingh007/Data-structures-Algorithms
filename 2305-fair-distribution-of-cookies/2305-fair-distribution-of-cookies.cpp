class Solution {
public:
    int res=INT_MAX;
    vector<int> dp;
    
    void fun(vector<int>& arr, int k,int p){
        if(p<0){
            int a=dp[0];
            for(int i=1;i<k;i++)
                a=max(a,dp[i]);
            res=min(res,a);
            return;
        }
        
        for(int i=0;i<k;i++){
            dp[i]+=arr[p];
            fun(arr,k,p-1);
            dp[i]-=arr[p];
        }
        return;
    }
    
    int distributeCookies(vector<int>& arr, int k) {
        int n=arr.size();
        dp.resize(k,0);
        
        fun(arr,k,n-1);
        return res;
    }
};