class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        //maintain two queue for front and back
        priority_queue<int, vector<int>, greater<int>> f,b;
        int cf = 0, cb = costs.size()-1;
        while(candidates > 0){
            f.push(costs[cf]);
            b.push(costs[cb]);
            cb--;
            cf++;
            if(cf == cb || cf > cb)  break;
            candidates--;
        }
        long long ans = 0;
        while(k > 0){
            k--;
            //if front queue is empty
            if(f.empty()){ 
                ans += b.top();
                b.pop();
                continue;
            }
            // if back queue is empty
            if(b.empty()){
                ans+=f.top();
                f.pop();
                continue;
            }

            if(f.top() > b.top()){
                ans += b.top();
                b.pop();
                if(cb >= cf ){
                    b.push(costs[cb]);
                    cb--;
                }
            }
            else{
                ans+=f.top();
                f.pop();
                if(cb >= cf){
                    f.push(costs[cf]);
                    cf++;
                }
            }
        }
        return ans;
    }
};