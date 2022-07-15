class Solution {
public:
    bool canChange(string s1, string s2) {
        string left="",right="";
        
        int n=s1.size();
        for(int i=0;i<n;i++){
            if(s2[i]=='L'){
                if(right.size()!=0 || s1[i]=='R')
                    return false;
                else if(s1[i]=='_')
                    left+='L';
            }
            else if(s2[i]=='R'){
                if(left.size()!=0 || s1[i]=='L')
                    return false;
                else if(s1[i]=='R')
                    continue;
                
                if(right.size()==0)
                    return false;
                else
                    right.pop_back();
            }
            else{
                if(s1[i]=='L'){
                    if(left.size()==0)
                        return false;
                    else
                        left.pop_back();
                }
                else if(s1[i]=='R'){
                    if(left.size()!=0)
                        return false;
                    else
                        right+='R';
                }   
            }
        }
        
        return (left.size()==0 && right.size()==0);
    }
};