class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char res=1;
        for(char c:letters){
            if(c>target){
                res=c;
                break;
            }
        }

        return res==1?letters[0]:res;
    }
};