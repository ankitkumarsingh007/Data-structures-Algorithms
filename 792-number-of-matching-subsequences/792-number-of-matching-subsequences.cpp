class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int n=s.size();
        vector<vector<int>> arr(n);
        
        vector<int> temp(26,-1);
        
        for(int i=n-1;i>=0;i--){
            arr[i]=temp;
            temp[s[i]-'a']=i;
        }
        
        int res=0;
        
        for(string &s:words){
            int i=temp[s[0]-'a'],j=1;
            
            while(j<s.size() && i!=-1){
                i=arr[i][s[j]-'a'];
                j++;
            }
            
            if(j==s.size() && i!=-1)
                res++;
        }
        
        return res;
    }
};