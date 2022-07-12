// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
        typedef long long ll;
        int closestToZero(int arr[], int n)
        {
            sort(arr,arr+n);
            
            ll res=arr[0]+arr[n-1];
            
            ll l=0,r=n-1;
            while(l<r){
                ll a=arr[l]+arr[r];
                
                if(abs(res)>abs(a) || (abs(res)==abs(a) && a>=0))
                res=a;
                
                
                if(a>0)
                r--;
                else
                l++;
            }
            
            return res;
        }
};

// { Driver Code Starts.
int main ()
{
    int t; 
    cin >> t;
    while (t--)
    {
        int n; 
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.closestToZero(arr, n) << endl;
    }
}  // } Driver Code Ends