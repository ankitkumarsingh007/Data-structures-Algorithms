class Solution {
public:
    void rotate(vector<vector<int>>& arr) {
        int n=arr.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++)
                swap(arr[i][j],arr[j][i]);
        }
        
        for(int i=0;i<n;i++)
        {
            int low=0,high=n-1;
            while(low<high)
            {
                swap(arr[i][low++],arr[i][high--]);
            }
        }
        return;
    }
};