class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();

        bool firstColumnHasZero = false;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    if(i==0){
                        firstColumnHasZero=true;
                    }else{
                        matrix[i][0]=0;
                        matrix[0][j]=0;
                    }
                }
            }
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(!matrix[i][0] || !matrix[0][j])
                matrix[i][j]=0;
            }
        }

        if(!matrix[0][0]){
            for(int i=1;i<m;i++)
            matrix[i][0]=0;
        }
        if(firstColumnHasZero){
            for(int i=0;i<n;i++){
                matrix[0][i]=0;
            }
        }

        return;
    }
};