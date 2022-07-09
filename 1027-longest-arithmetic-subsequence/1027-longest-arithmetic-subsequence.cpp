class Solution {
public:
    int longestArithSeqLength(vector<int>& arr) {
        int res=1,n=arr.size();

        vector<unordered_map<int,int>> dp(n);

        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                int d=arr[i]-arr[j],curr;

                if(dp[j].find(d)==dp[j].end())
                curr=2;
                else
                curr=dp[j][d]+1;

                dp[i][d]=max(dp[i][d],curr);
                res=max(res,curr);
            }
        }

        return res;
    }
};