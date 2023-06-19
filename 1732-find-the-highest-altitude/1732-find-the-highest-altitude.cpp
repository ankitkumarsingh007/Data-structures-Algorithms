class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int curr=0,res=0;
        
        for(int a:gain){
            curr+=a;
            res=max(res,curr);
        }
        
        return res;
    }
};