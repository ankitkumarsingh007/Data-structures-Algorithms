class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> res;
        
        int even=0;
        
        for(int x:arr){
            if(x%2==0)
                even+=x;
        }
        
        
        for(auto v:queries){
            int i=v[1],val=v[0];
            
            if(arr[i]%2==0)
                even-=arr[i];
            arr[i]+=val;
            
            if(arr[i]%2==0)
                even+=arr[i];
            
            res.push_back(even);
        }
        
        return res;
    }
};