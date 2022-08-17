class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string arr[26]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        unordered_set<string> st;
        
        for(string s:words){
            string curr="";
            for(char c:s){
                curr+=arr[c-'a'];
            }
            
            st.insert(curr);
        }
        
        return st.size();
    }
};