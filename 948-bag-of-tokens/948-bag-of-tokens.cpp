class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        
        if(tokens.size()==0 || tokens[0]>power)
            return 0;
        
        power-=tokens[0];
        int res=1,curr=1,i=1,j=tokens.size()-1;
        
        while(i<=j){
            if(power>=tokens[i]){
                power-=tokens[i++];
                curr++;
                
                res=max(res,curr);
            }
            else if(curr!=0){
                power+=tokens[j--];
                curr--;
            }
            else
                break;
        }
        
        return res;
    }
};