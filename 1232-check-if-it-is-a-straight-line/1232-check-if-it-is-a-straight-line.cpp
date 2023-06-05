class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        
        double l=(arr[1][1]-arr[0][1])/(arr[1][0]-arr[0][0]*1.0);
        
        for(int i=2;i<n;i++){
            double curr=(arr[i][1]-arr[i-1][1])/(arr[i][0]-arr[i-1][0]*1.0);
            if(l!=curr)
                return false;
        }
        return true;
    }
};