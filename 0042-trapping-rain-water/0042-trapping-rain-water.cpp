class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size(),res=0;
        
        int pos=max_element(height.begin(),height.end())-height.begin();
        int l=height[0],r=height[n-1],val=height[pos];
        
        for(int i=1;i<pos;i++){
            res+=max(0,l-height[i]);
            l=max(l,height[i]);
        }
        for(int i=n-2;i>pos;i--){
            res+=max(0,r-height[i]);
            r=max(r,height[i]);
        }
        
        return res;
    }
};


