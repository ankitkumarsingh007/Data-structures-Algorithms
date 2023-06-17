class Solution {
public:

    int binarySearch(vector<int>& arr, int num)
    {
        int l = 0, h = arr.size()-1;
        int m;
        while(l<=h)
        {
            m = (l+h)/2;
            if(arr[m] <= num) l = m+1;
            else
            {
                if(m == 0) return m;
                if(arr[m-1] <= num) return m;
                h = m-1;
            }
        }
        return -1;
    }

    map<pair<int,int>,int> dp;
    int solve(vector<int>& arr1, vector<int>& arr2, int prev,int idx)
    {
        if(idx == arr1.size()) return 0;

        if(dp.find({idx, prev}) != dp.end()) return dp[{idx, prev}];
        int cost = 3000;
        int i = binarySearch(arr2, prev);

        if(arr1[idx] > prev)
        {
            cost = solve(arr1, arr2, arr1[idx], idx+1);
            if(i != -1)
                cost = min(cost, 1+ solve(arr1, arr2, arr2[i], idx+1));
        }    
        else if(arr1[idx] <= prev && i != -1)
        {
            cost = 1 + solve(arr1, arr2, arr2[i], idx+1);
        }
        
        return dp[{idx, prev}] = cost;
    }

    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        
        sort(arr2.begin(), arr2.end());
       
        int n = solve(arr1, arr2, -1, 0);
        if(n >= 3000)
            return -1;
        return n;
    }
};