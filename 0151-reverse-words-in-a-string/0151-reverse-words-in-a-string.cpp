class Solution {
public:
    string reverseWords(string s) {
        string res="",curr="";
        
        for(char c:s){
            if(c==' '){
                if(curr!=""){
                    reverse(curr.begin(),curr.end());
                    if(res=="")
                        res+=curr;
                    else{
                        res+=" ";
                        res+=curr;
                    }
                    curr="";
                }
            }
            else
                curr+=c;
        }
        
        if(curr!=""){
            reverse(curr.begin(),curr.end());
            if(res=="")
                res+=curr;
            else{
                res+=" ";
                res+=curr;
            }
            curr="";
        }
        
        reverse(res.begin(),res.end());
        return res;
    }
};