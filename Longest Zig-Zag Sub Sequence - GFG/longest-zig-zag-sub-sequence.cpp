// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		int ZigZagMaxLength(vector<int>&arr){
            int n=arr.size();
            if(n==1)
                return 1;
            
            vector<int> up(n,1),down(n,1);
            
            int res=1;
            for(int i=1;i<n;i++){
                if(arr[i]>arr[i-1]){
                    up[i]=down[i-1]+1;
                    down[i]=down[i-1];
                }
                else if(arr[i]<arr[i-1]){
                    down[i]=1+up[i-1];
                    up[i]=up[i-1];
                }
                else{
                    up[i]=up[i-1];
                    down[i]=down[i-1];
                }
            }
            
            return max(down[n-1],up[n-1]);
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.ZigZagMaxLength(nums);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends