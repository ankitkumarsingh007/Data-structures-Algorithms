class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        vector<bool> row(m,false),column(n,false);

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!matrix[i][j]){
                    row[i]=true;
                    column[j]=true;
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(row[i] || column[j])
                matrix[i][j]=0;
            }
        }

        return;
    }
};