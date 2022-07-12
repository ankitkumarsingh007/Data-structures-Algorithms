class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        
        int n=s.size();
        
        for(int i=0;i<n;i++){
            if(s[i]=='(')
            st.push(i);
            else{
                if(!st.empty() && s[st.top()]=='(')
                st.pop();
                else
                st.push(i);
            }
        }
        
        if(st.empty())
        return s.size();
        
        int last=n,res=0;
        while(!st.empty()){
            res=max(res,last-st.top()-1);
            last=st.top();
            st.pop();
        }
        
        res=max(res,last);
        
        return res;
    }
};