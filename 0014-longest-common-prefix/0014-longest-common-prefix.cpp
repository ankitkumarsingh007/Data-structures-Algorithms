class Solution {
public:
    string longestCommonPrefix(vector<string>& arr) {
        int n=arr.size(),limit=INT_MAX;
        
        for(string s:arr)
            limit=min(limit,int(s.size()));
        
        string res="";
        for(int i=0;i<limit;i++){
            char c=arr[0][i];
            
            for(int j=1;j<n;j++)
                if(arr[j][i]!=c)
                    return res;
            
            res+=c;
        }
        
        return res;
    }
};