class Solution {
public:
    vector<int> productExceptSelf(vector<int>& arr) {
        int n=arr.size();
        
        vector<int> res(n,1);
        int l=1;
        
        for(int i=n-2;i>=0;i--){\
            res[i]=res[i+1]*arr[i+1];
        }
        
        for(int i=1;i<n;i++){
            l*=arr[i-1];
            res[i]*=l;
        }
        
        return res;
    }
};