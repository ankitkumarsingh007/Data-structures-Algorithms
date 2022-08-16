class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> arr(26,-1);
        
        int n=s.size();
        for(int i=0;i<n;i++){
            int a=s[i]-'a';
            if(arr[a]==-1)
                arr[a]=i;
            else
                arr[a]=-2;
        }
        
        int res=INT_MAX;
        
        for(int i=0;i<26;i++){
            if(arr[i]>=0)
            res=min(res,arr[i]);
        }
        
        return res==INT_MAX?-1:res;
    }
};