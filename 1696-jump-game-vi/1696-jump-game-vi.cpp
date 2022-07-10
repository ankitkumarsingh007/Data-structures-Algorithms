class Solution {
public:
    int maxResult(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n,0);
        dp[0]=arr[0];
        
        deque<int> q;
        q.push_back(0);
        
        for(int i=1;i<n;i++){
            if(q.front()<(i-k))
                q.pop_front();
            
            dp[i]=dp[q.front()]+arr[i];
            
            while(!q.empty() && dp[i]>dp[q.back()])
                q.pop_back();
            q.push_back(i);
        }
        
        return dp[n-1];
    }
};