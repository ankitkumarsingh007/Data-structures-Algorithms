class Solution {
public:
    int climbStairs(int n) {
        if(n<3)
            return n;
        
        int prev=2,prev_prev=1,a;
        
        for(int i=3;i<=n;i++){
            a=prev+prev_prev;
            prev_prev=prev;
            prev=a;
        }
        
        return a;
    }
};