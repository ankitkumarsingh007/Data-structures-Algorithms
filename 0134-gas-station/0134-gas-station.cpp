class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int prev=0,curr=0,res=0,n=gas.size();
        
        for(int i=0;i<n;i++){
            curr+=(gas[i]-cost[i]);
            
            if(curr<0){
                prev+=curr;
                curr=0;
                res=i+1;
            }
        }
        
        return prev+curr>=0?res:-1;
    }
};