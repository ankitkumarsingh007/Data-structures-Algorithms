// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    // Function to find element in sorted array
    // arr: input array
    // N: size of array
    // K: element to be searche
    int ternarySearch(int ar[], int N, int key) 
    { 
        int l=0,r=N-1;
        while (r >= l) {
    
            int mid1 = l + (r - l) / 3;
            int mid2 = r - (r - l) / 3;
    
            if (ar[mid1] == key) {
                return 1;
            }
            if (ar[mid2] == key) {
                return 1;
            }
    
            if (key < ar[mid1]) {
                r = mid1 - 1;
            }
            else if (key > ar[mid2]) {
                l = mid2 + 1;
            }
            else {
                l = mid1 + 1;
                r = mid2 - 1;
            }
        }
    
        return -1;
    }
};

// { Driver Code Starts.
int main(void) 
{ 
    
    int t;
    cin >> t;
    while(t--){
        int N, K;
        cin >> N >> K;
        
        int arr[N];
        
        for(int i = 0;i<N;i++){
            cin >> arr[i];
        }
        Solution ob;
        cout << ob.ternarySearch(arr, N, K) << endl;

    }

	return 0; 
} 
  // } Driver Code Ends