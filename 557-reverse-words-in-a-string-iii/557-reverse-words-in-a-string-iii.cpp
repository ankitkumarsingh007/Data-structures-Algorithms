class Solution {
public:
    string reverseWords(string s) {
        string res="";
        stack<char> st;
        
        for(char c:s){
            if(c==' '){
                while(!st.empty()){
                    res+=st.top();
                    st.pop();
                }
                res+=' ';
            }
            else
            st.push(c);
        }
        
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        
        return res;
    }
};