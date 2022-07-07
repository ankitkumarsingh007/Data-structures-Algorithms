// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	
    bool brainGame(vector<int>nums) {
        vector<bool> prime(1001,true);
        int res=0;
        
        for(int i=2;i<1001;i++){
            if(prime[i]){
                for(int j=i*i;j<1001;j+=i)
                prime[j]=false;
            }
        }
        
        for(int x:nums){
            int cnt=0,s=sqrt(x);
            for(int i=2;i<=s;i++){
                while(!prime[x] && x%i==0){
                    cnt++;
                    x/=i;
                }
            }
            
            res^=cnt;
        }
        
        return res;
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
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution ob;
		bool ans = ob.brainGame(nums);
		if(ans)
			cout << "A\n";
		else cout << "B\n";
	}  
	return 0;
}  // } Driver Code Ends