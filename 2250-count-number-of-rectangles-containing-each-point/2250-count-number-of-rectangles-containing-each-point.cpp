class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        vector<vector<int>> dp(101);
        
        for(auto v:rectangles){
            dp[v[1]].push_back(v[0]);
        }
        for(int i=1;i<=100;i++)
            sort(dp[i].begin(),dp[i].end());
        
        vector<int> res;
        for(auto v:points){
            int curr=0;
            for(int i=v[1];i<101;i++){
                    if(dp[i].size()!=0)
                    curr+=(dp[i].end()-lower_bound(dp[i].begin(),dp[i].end(),v[0]));
            }
            res.push_back(curr);
        }
        
        return res;
    }
};