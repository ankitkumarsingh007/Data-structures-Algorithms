class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        vector<int> count(101,0);
        
        for(int r=m-1;r>=0;r--){
            int total=min(n,m-r);
            
            for(int i=r,j=0,t=total;t!=0;i++,j++,t--){
                count[mat[i][j]]++;
            }
            
            int k=0;
            
            for(int i=r,j=0,t=total;t!=0;i++,j++,t--){
                while(k<101 && count[k]==0)
                    k++;
                count[k]--;
                mat[i][j]=k;
            }
        }
        
        for(int c=1;c<n;c++){
            int total=min(m,n-c);
            
            for(int i=0,j=c,t=total;t!=0;i++,j++,t--){
                count[mat[i][j]]++;
            }
            
            int k=0;
            
            for(int i=0,j=c,t=total;t!=0;i++,j++,t--){
                while(k<101 && count[k]==0)
                    k++;
                count[k]--;
                mat[i][j]=k;
            }
        }
        
        return mat;
    }
};

