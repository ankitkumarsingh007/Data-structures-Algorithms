class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> arr(26,0);
        
        for(char c:magazine)
            arr[c-'a']++;
        
        for(char c:ransomNote){
            if(arr[c-'a']==0)
                return false;
            arr[c-'a']--;
        }
        
        return true;
    }
};