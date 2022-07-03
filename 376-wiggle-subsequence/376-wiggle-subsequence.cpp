class Solution {
public:
    int wiggleMaxLength(vector<int>& arr) {
        int n=arr.size();
        if(n==1)
            return 1;
        
        vector<int> up(n,1),down(n,1);
        
        int res=1;
        for(int i=1;i<n;i++){
            if(arr[i]>arr[i-1]){
                up[i]=down[i-1]+1;
                down[i]=down[i-1];
            }
            else if(arr[i]<arr[i-1]){
                down[i]=1+up[i-1];
                up[i]=up[i-1];
            }
            else{
                up[i]=up[i-1];
                down[i]=down[i-1];
            }
        }
        
        return max(down[n-1],up[n-1]);
    }
};