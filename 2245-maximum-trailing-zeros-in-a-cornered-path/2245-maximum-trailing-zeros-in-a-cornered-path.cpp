class Solution {
public:
    typedef pair<int,int> pp;
    
    vector<pp> fact;
    Solution(){
        fact.resize(1001);
        fact[1]={0,0};
        
        for(int i=2;i<1001;i++){
            int a=i;
            int c=0,d=0;
            while(a%2==0){
                c++;
                a/=2;
            }
            while(a%5==0){
                d++;
                a/=5;
            }
            
            fact[i]={c,d};
        }
    }
    
    int maxTrailingZeros(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        
        vector<vector<pp>> left(m,vector<pp>(n,{0,0}));
        vector<vector<pp>> right(m,vector<pp>(n,{0,0}));
        vector<vector<pp>> top(m,vector<pp>(n,{0,0}));
        vector<vector<pp>> bottom(m,vector<pp>(n,{0,0}));
        vector<vector<pp>> arr(m,vector<pp>(n,{0,0}));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                arr[i][j]=fact[grid[i][j]];
            }
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(j==0)
                    left[i][j]=arr[i][j];
                else
                    left[i][j]={arr[i][j].first+left[i][j-1].first,arr[i][j].second+left[i][j-1].second};
            }
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0)
                    top[i][j]=arr[i][j];
                else
                    top[i][j]={arr[i][j].first+top[i-1][j].first,arr[i][j].second+top[i-1][j].second};
            }
        }
        
        for(int i=m-1;i>=0;i--){
            for(int j=0;j<n;j++){
                if(i==(m-1))
                    bottom[i][j]=arr[i][j];
                else
                    bottom[i][j]={arr[i][j].first+bottom[i+1][j].first,arr[i][j].second+bottom[i+1][j].second};
            }
        }
        
        for(int i=0;i<m;i++){
            for(int j=n-1;j>=0;j--){
                if(j==(n-1))
                    right[i][j]=arr[i][j];
                else
                    right[i][j]={arr[i][j].first+right[i][j+1].first,arr[i][j].second+right[i][j+1].second};
            }
        }
        
        int res=0;
        
        for(int j=0;j<n;j++){
            for(int i=0;i<m;i++){
                pp a1=top[i][j],a2=bottom[i][j];
                
                int a=max(a1.first,a2.first),b=max(a1.second,a2.second);
                a-=arr[i][j].first,b-=arr[i][j].second;
                
                int curr=max(min(a+left[i][j].first,b+left[i][j].second),min(a+right[i][j].first,b+right[i][j].second));
                
                res=max(res,curr);
            }
        }
        
        return res;
    }
};