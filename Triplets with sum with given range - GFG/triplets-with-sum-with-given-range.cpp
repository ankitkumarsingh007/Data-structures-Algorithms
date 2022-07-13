// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
   int countTripletsLessThan(int arr[],int n,int x){
       int res=0;
       for(int i=0;i<n-2;i++){
           int j=i+1,k=n-1;
           
           while(j<k){
               int sum=arr[i]+arr[j]+arr[k];
               
               if(sum>x)
               k--;
               else{
                   res+=(k-j);
                   j++;
               }
           }
       }
       
       return res;
   }
  
    int countTriplets(int arr[], int n, int l, int r) {
        sort(arr,arr+n);
        
        int res=countTripletsLessThan(arr,n,r)-countTripletsLessThan(arr,n,l-1);
        
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int Arr[N];
        for (int i = 0; i < N; i++) cin >> Arr[i];
        int L, R;
        cin >> L >> R;
        Solution obj;
        cout << obj.countTriplets(Arr, N, L, R) << endl;
    }
    return 0;
}  // } Driver Code Ends