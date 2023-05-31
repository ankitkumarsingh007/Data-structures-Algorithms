class Solution {
public:
    int lengthOfLastWord(string s) {
        int last=0,curr=0;
        
        for(char c:s){
            if(c==' '){
                if(curr!=0)
                    last=curr;
                curr=0;
            }
            else
                curr++;
        }
        
        if(curr!=0)
            last=curr;
        
        return last;
    }
};