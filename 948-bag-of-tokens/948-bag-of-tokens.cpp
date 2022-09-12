class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        //(1) First sort tokens array so that we buy higher powers with same score
        //(2) & then sell cheaper ones to earn scores easily
        sort(tokens.begin(),tokens.end());
        
        //Corner cases
        if(tokens.size()==0 || tokens[0]>power)
            return 0;
        
        power-=tokens[0];
        int res=1,curr=1,i=1,j=tokens.size()-1;
        
        //simple 2 pointer approach is applied here
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