class Solution {
public:
    //Note - If we are considering prefix sum for rows , then we will iterate 2 times on column
    //and for each case will traverse each row to include each case , So TC=O(mnn)
    //Note - If we are considering prefix sum for columns , then we will iterate 2 times on rows
    //and for each case will traverse each column to include each case , So TC=O(mmn)
    
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(),n=matrix[0].size();
        
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++)
                matrix[j][i]=matrix[j][i-1]+matrix[j][i];
        }
        
        int res=0;
        
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                
                unordered_map<int,int> mp;
                mp[0]=1;
                int curr=0;
                for(int k=0;k<m;k++){
                    int add=matrix[k][j]-(i>0?matrix[k][i-1]:0);
                    
                    curr+=add;
                    if(mp.find(curr-target)!=mp.end())
                        res+=mp[curr-target];
                    mp[curr]++;
                }
            }
        }
        
        return res;
    }
};