class Solution {
public:
    typedef pair<int,pair<int,int>> pp;
    int kthSmallest(vector<vector<int>>& arr, int k) {
        int n=arr.size();
        priority_queue<pp,vector<pp>,greater<pp>> pq;
    
        for(int i=0;i<n;i++)
        {
            pq.push({arr[i][0],{i,0}});
        }

        k--;

        while(k--)
        {
            pp temp=pq.top();
            pq.pop();

            int i=temp.second.first,j=temp.second.second;

            if(j!=(n-1))
            {
                pq.push({arr[i][j+1],{i,j+1}});
            }
        }
        return pq.top().first;
    }
};