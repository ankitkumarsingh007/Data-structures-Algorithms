// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int CountPS(char S[], int N);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        char S[N+1];
        cin>>S;
        cout<<CountPS(S,N)<<endl;
    }
    return 0;
}

// } Driver Code Ends


int CountPS(char s[], int n)
{
    vector<vector<int>> dp(n,vector<int>(n,0));
    vector<vector<bool>> p(n,vector<bool>(n,true));
    if(n==1)
    return 1;
    
    for(int i=0;i<n-1;i++){
        if(s[i]==s[i+1])
        dp[i][i+1]=1;
        else
        p[i][i+1]=false;
    }
    
    for(int gap=2;gap<n;gap++){
        for(int i=0,j=gap;j<n;i++,j++){
            if(s[i]!=s[j] || !p[i+1][j-1])
            p[i][j]=false;
            
            if(p[i][j])
            dp[i][j]=dp[i][j-1]+dp[i+1][j]+1-dp[i+1][j-1];
            else
            dp[i][j]=dp[i][j-1]+dp[i+1][j]-dp[i+1][j-1];
        }
    }
    
    return dp[0][n-1];
}