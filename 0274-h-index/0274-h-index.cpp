class Solution {
public:
    int hIndex(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        
        int res=-1;
        for(int i=0;i<n;i++){
            res=max(res,min(arr[i],n-i));
        }
        
        return res;
    }
};