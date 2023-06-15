class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int start=0,size=1;
        
        for(int i=1;i<n;i++){
            int l,r;
            
            //even part
            l=i-1,r=i;
            while(l>=0 && r<n && s[l]==s[r]){
                if((r-l+1)>size){
                    size=r-l+1;
                    start=l;
                }
                l--,r++;
            }
            
            //odd part
            l=i-1,r=i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                if((r-l+1)>size){
                    size=r-l+1;
                    start=l;
                }
                l--,r++;
            }
        }
        
        return s.substr(start,size);
    }
};