class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        bool dp[n+1][m+1];
        memset(dp,false, sizeof(dp));
        dp[0][0] = true;

        // if i>0 && j==0, it means p ended, still char in s is remaininmg so by default false
        // However if i==0 and j>0 we need to check first, coz in case of (a*) we can merge it to empty pattern

        for(int i=0;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(p[j-1]=='*'){
                    // 0 prev character matched || prev character matched
                    dp[i][j] = dp[i][j-2] || (i>0 && (s[i-1]==p[j-2] || p[j-2]=='.')) && dp[i-1][j];
                }else{
                    dp[i][j] = i>0 && (s[i-1]==p[j-1] || p[j-1]=='.') && dp[i-1][j-1];
                }
            }
        }
        return dp[n][m];
    }
};