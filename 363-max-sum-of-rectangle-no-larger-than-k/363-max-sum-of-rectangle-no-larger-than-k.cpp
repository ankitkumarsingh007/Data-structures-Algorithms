class Solution {
public:
    int helper(vector<int> v,int k){
        set<int> total;
        total.insert(0);

        int res=INT_MIN,n=v.size();

        for(int i=0;i<n;i++){
            auto it=total.lower_bound(v[i]-k);

            if(it!=total.end())
            res=max(res,v[i]-*it);

            total.insert(v[i]);
        }
        return res;
    }
    
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m=matrix.size(),n=matrix[0].size(),res=INT_MIN;
        
        for(int i=0;i<m;i++){
            for(int j=1;j<n;j++)
                matrix[i][j]+=matrix[i][j-1];
        }
        
        for(int j=0;j<n;j++){
            for(int i=1;i<m;i++)
                matrix[i][j]+=matrix[i-1][j];
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<=i;j++){
                if(j==0)
                res=max(res,helper(matrix[i],k));
                else{
                    vector<int> v=matrix[i];
                    for(int k=0;k<n;k++)
                        v[k]-=matrix[j-1][k];
                    
                    res=max(res,helper(v,k));
                }
            }
        }
        
        return res==INT_MIN?-1:res;
    }
};