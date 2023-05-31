class Solution {
public:
    int candy(vector<int>& arr) {
        int n=arr.size();
        int candy=n,i=1;
        
        while(i<n){
            while(i<n && arr[i]==arr[i-1]){
                i++;
                continue;
            }
            
            int peak=0;
            while(i<n && arr[i]>arr[i-1]){
                peak++;
                candy+=peak;
                i++;
            }
            if(i==n)
                break;
            
            int valley=0;
            while(i<n && arr[i]<arr[i-1]){
                valley++;
                candy+=valley;
                i++;
            }
            
            candy-=min(peak,valley);
        }
        
        return candy;
    }
};