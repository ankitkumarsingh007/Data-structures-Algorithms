// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  //find next grater element & if after that a smaller element is found just return false
  
  //for that maintain stack , element will be pushed till they are smaller than st.top()
  //after that whenever greater element is found pop all elements from stack and store maxm no as root
  //2 reason for that
  //(1) Stack has been storing no in decreasing order and we want maxm no as our root
  //(2) we want maximum no as root bcz if value after greater will be less than this it means it will be less
  //than popped itmes too , so just return false
    int canRepresentBST(int arr[], int n) {
        int root=INT_MIN;
        stack<int> st;
        
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[i]>st.top()){
                root=st.top();
                st.pop();
            }
            
            if(arr[i]<root)
            return false;
            
            st.push(arr[i]);
        }
        
        return true;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];
        Solution ob;
        cout << ob.canRepresentBST(arr, N) << endl;
    }
    return 0;
}  // } Driver Code Ends