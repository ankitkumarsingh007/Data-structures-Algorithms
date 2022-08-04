class Solution {
public:
    int mirrorReflection(int p, int q) {
        int m = q, n = p;
        while(m % 2 == 0 && n % 2 == 0){
            m /= 2;
            n /= 2;
        }
        
        if(n%2==1){
            if(m%2==1)
                return 1;
            else
                return 0;
        }
        else
            return 2;
    }
};