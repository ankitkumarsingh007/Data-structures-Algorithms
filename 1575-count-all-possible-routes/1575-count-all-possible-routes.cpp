class Solution {
public:
    int dp[205][205];
    int mod = 1e9+7;
    int helper(vector<int>& locations, int start, int finish, int fuel){
        if(fuel<0) return 0;
        if(dp[start][fuel]!=-1) return dp[start][fuel];
        int ans = 0;
        if(start == finish){
            ans++;
        }
        for(int i=0;i<locations.size();i++){
            if(i!=start){
                int subans = helper(locations, i, finish, fuel-abs(locations[i] - locations[start]));
                ans = (ans+subans)%mod;
            }
        }
        return dp[start][fuel] = ans%mod;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        memset(dp,-1,sizeof(dp));
        return helper(locations,start,finish,fuel);
    }
};