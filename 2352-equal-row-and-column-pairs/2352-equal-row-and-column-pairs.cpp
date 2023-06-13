class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n=grid.size(),res=0;
        map<string,int> mp;
        
        for(auto v:grid){
            string s="";
            for(int a:v){
                if(s!="")
                    s+='&';
                s+=to_string(a);
            }
            mp[s]++;
        }
        
        for(int i=0;i<n;i++){
            string s="";
            for(int j=0;j<n;j++){
                if(s!="")
                    s+='&';
                s+=to_string(grid[j][i]);
            }
            
            res+=mp[s];
        }
        
        return res;
    }
};