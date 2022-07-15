class Solution {
public:
    string digitSum(string s, int k) {
        string res="";
        int n=s.size();
        if(n<=k)
            return s;
        
        
        for(int i=0;i<n;i+=k){
            int curr=0,l=min(i+k,n);
            
            for(int j=i;j<l;j++){
                curr+=(s[j]-'0');
            }
            res+=to_string(curr);
        }
        
        return res.size()>k?digitSum(res,k):res;
    }
};