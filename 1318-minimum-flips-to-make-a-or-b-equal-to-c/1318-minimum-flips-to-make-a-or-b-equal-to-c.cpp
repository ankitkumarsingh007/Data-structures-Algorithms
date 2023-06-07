class Solution {
public:
    int minFlips(int a, int b, int c) {
        int res=0;
        for(int i=31;i>=0;i--){
            if(((1<<i)&c)==0){
                if(((1<<i)&a))
                    res++;
                if(((1<<i)&b))
                    res++;
            }
            else{
                if(!((1<<i)&a) && !((1<<i)&b))
                    res++;
            }
            
        }
        
        return res;
    }
};