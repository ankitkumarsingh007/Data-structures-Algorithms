class Solution {
public:
    string maximumBinaryString(string s) {
        int n=s.size(),start=-1,cnt=0;
        
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                if(cnt==0)
                    start=i;
                
                cnt++;
            }
            s[i]='1';
        }
        
        if(start!=-1)
        s[start+cnt-1]='0';
        
        return s;
    }
};