// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    vector<vector<int> > subsets(vector<int>& arr)
    {
        vector<vector<int>> res;
        int n=arr.size();
        int l=pow(2,n);
        
        for(int i=0;i<l;i++){
            vector<int> v;
            for(int j=0;j<n;j++)
                if(((1<<j)&i))
                    v.push_back(arr[j]);
            res.push_back(v);
        }
        sort(res.begin(),res.end());
        
        return res;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n, x;
		cin >> n;

		vector<int> array;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			array.push_back(x);
		}
        
        
        Solution ob;
		vector<vector<int> > res = ob.subsets(array);

		// Print result
		for (int i = 0; i < res.size(); i++) {
			for (int j = 0; j < res[i].size(); j++)
				cout << res[i][j] << " ";
			cout << endl;
		}

		
	}

	return 0;
}  // } Driver Code Ends