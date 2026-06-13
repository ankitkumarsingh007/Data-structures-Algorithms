class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> l(n,-1), r(n,-1);

        for(int i=0;i<n;i++){
            if(i==0)
            l[i] = height[i];
            else
            l[i] = max(l[i-1],height[i]);
        }

        for(int i=n-1;i>=0;i--){
            if(i==(n-1))
            r[i] = height[i];
            else
            r[i] = max(r[i+1],height[i]);
        }

        int res = 0;
        for(int i=1;i<(n-1);i++){
            res+=max(0,min(l[i],r[i])-height[i]);
        }

        return res;
    }
};