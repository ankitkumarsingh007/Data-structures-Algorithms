class Solution {
public:
    string removeKdigits(string s, int k) {
        int n=s.size();
        
        stack<char> st;
        for(char c:s){
            while(!st.empty() && k!=0 && st.top()>c){
                st.pop();
                k--;
            }
            
            st.push(c);
        }
        
        string res="";
        while(!st.empty() && k!=0){
            st.pop();
            k--;
        }
        
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        for(int i=res.size()-1;i>=0;i--){
            if(res[i]=='0')
            res.pop_back();
            else
            break;
        }
        
        reverse(res.begin(),res.end());
        
        return res.size()==0?"0":res;
    }
};