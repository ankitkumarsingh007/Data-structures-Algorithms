class Solution {
public:
    typedef pair<int,pair<int,int>> pp;
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        priority_queue<pp,vector<pp>,greater<pp>> pq;
        pq.push({matrix[0][0],{0,0}});
        
        k--;
        while(k--){
            pp curr=pq.top();
            pq.pop();
            int a=curr.second.first,b=curr.second.second;
            
            if(a<(n-1) && matrix[a+1][b]!=INT_MAX){
                pq.push({matrix[a+1][b],{a+1,b}});
                matrix[a+1][b]=INT_MAX;
            }
            if(b<(n-1) && matrix[a][b+1]!=INT_MAX){
                pq.push({matrix[a][b+1],{a,b+1}});
                matrix[a][b+1]=INT_MAX;
            }
        }
        
        return pq.top().first;
    }
};