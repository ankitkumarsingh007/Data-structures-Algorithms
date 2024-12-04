class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i=0,m=str2.size();
        
        for(char c:str1){
            if((str2[i]-c+26)%26 <= 1)
                i++;
            if(i==m)
                return true;
        }
        
        return false;
    }
};