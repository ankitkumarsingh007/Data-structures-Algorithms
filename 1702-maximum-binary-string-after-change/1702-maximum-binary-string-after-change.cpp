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
        }
        
        string res="";
        for(int i=0;i<n;i++){
            if(i==(start+cnt-1))
                res+='0';
            else
                res+='1';
        }
        
        return res;
    }
};