// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int h[4]={-1,1,0,0};
    int v[4]={0,0,-1,1};
    typedef pair<int,int> pp;
    bool valid(int i,int j,int m,int n){
        if(i>=0 && i<m && j>=0 && j<n)
            return true;
        return false;
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(newColor==image[sr][sc])
            return image;
        
        int x=image[sr][sc];
        int m=image.size(),n=image[0].size();
        
        queue<pp> q;
        q.push({sr,sc});
        image[sr][sc]=newColor;
        
        while(!q.empty()){
            pp curr=q.front();
            q.pop();
            for(int k=0;k<4;k++){
                int i=h[k]+curr.first,j=v[k]+curr.second;
                if(valid(i,j,m,n) && image[i][j]==x){
                    q.push({i,j});
                    image[i][j]=newColor;
                }
            }
        }
        
        return image;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends