class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        vector<int> in(numCourses,0);
        
        for(auto v:prerequisites){
            adj[v[1]].push_back(v[0]);
            in[v[0]]++;
        }
        
        int cnt=0;
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(in[i]==0)
                q.push(i);
        }
        
        while(!q.empty()){
            int x=q.front();
            q.pop();
            cnt++;
            
            for(int a:adj[x]){
                in[a]--;
                if(in[a]==0)
                    q.push(a);
            }
        }
        
        return cnt==numCourses;
    }
};