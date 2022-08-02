class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int l=matrix[0][0], r=matrix[n-1][n-1], mid;
        while(l<r){
            mid=(l+r)>>1;
            // mid=(l+r)/2;
            int cnt=0, j=n-1;
            
            for(int i=0;i<n;i++){
                while(j>=0 && matrix[i][j]>mid)
                    j--;
                cnt+=(j+1);
            }
            
            if(cnt<k)
                l=mid+1;
            else
                r=mid;
        }
        return l;
    }
};