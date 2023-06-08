class Solution {
private:
    int binarySearch(vector<int>&row){
        int n = row.size();

        int start=0;
        int end = n-1;
        int mid;
        
        //edge case if row[0] is negative number; prevents access to null from the beginning of vector
        if(row[start]<0)
        return start;

        while(start<=end){
            mid = start + (end-start)/2;
            
            if(row[mid]<0 && row[mid-1]>=0)
            return mid;
            else if(row[mid]>=0)
            start = mid+1;
            else
            end = mid-1;
        }
        return -1;
    }
public:
    int countNegatives(vector<vector<int>>& grid) {
        //we perform binary search for all rows
        int count = 0;
        int m = grid.size();
        int n = grid[0].size();

        for(int i=0;i<m;i++){
            int index = binarySearch(grid[i]);
            //cout<<index;
            
            //if no negative integer in the vector
            if(index==-1)
            continue;

            //count negatives for each iteration and sum up
            count+=n-index;
        }
        return count;
    }
};