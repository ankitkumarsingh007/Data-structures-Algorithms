// { Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    typedef pair<int,int> pp;
    
    // static bool comp(pp &a,pp &b){
    //     if(a.first==b.first)
    //     return a.second<b.second;
    //     else
    //     return a.first<b.first;
    // }
    
    int min_sprinklers(int arr[], int n)
    {
        vector<pp> aux;
        
        for(int i=0;i<n;i++){
            if(arr[i]==-1)
            continue;
            else{
                int l=max(0,i-arr[i]),r=min(n-1,i+arr[i]);
                aux.push_back({l,r});
            }
        }
        
        sort(aux.begin(),aux.end());
        
        int maxRight=0,res=0,i=0;
        
        while(maxRight<n){
            if(i==aux.size() || aux[i].first>maxRight)
            return -1;
            
            int currMax=aux[i].second;
            i++;
            
            while(i<aux.size() && aux[i].first<=maxRight){
                currMax=max(currMax,aux[i].second);
                i++;
            }
            //it means new possble max will be same as prev step
            if(currMax<maxRight)
            return -1;
            
            res++;
            maxRight=currMax+1;
            
        }
        
        return res;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        int gallery[n];
        for(int i=0; i<n; i++)
            cin>> gallery[i];
        Solution obj;
        cout<< obj.min_sprinklers(gallery,n) << endl;
    }
	return 1;
}
  // } Driver Code Ends