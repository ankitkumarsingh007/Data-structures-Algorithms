class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0)
            return false;
        
        if((n&(n-1))!=0)
            return false;
        
        int cnt=0;
        while((n&1)!=1){
            n>>=1;
            cnt++;
        }
        
        return cnt%2==0;
    }
};